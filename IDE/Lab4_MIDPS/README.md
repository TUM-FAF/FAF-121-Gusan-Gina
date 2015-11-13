##One bug, one crash: the story of Ariane 5

####“Sometimes a Bug Is More Than a Nuisance”

In order to build Ariane 5, known as a giant rocket capable of releasing a pair of three-ton satellites into orbit with each launch, it took the European Space Agency 10 years and huge resources (over 7 billion $). This aspiring project was intended to give Europe overwhelming supremacy in the commercial space business. 

 At 39 seconds after launch on 4 June 1996, in Kourou, French Guiana, as the rocket reached an altitude of 3700 m, a self-destruct mechanism finished off Ariane 5 in a massive explosion, along with its payload of four expensive and uninsured scientific satellites. All it took to explode that rocket in less than a minute after its maiden fight, was a small computer script trying to cram a 64-bit number into a 16-bit space.

The conversion error occurred in a routine which had been reused from the Ariane 4 vehicle. During design of the software of the inertial reference system used for Ariane 4 and Ariane 5, a decision was taken that it was not necessary to protect the inertial system computer from being made inoperative by an excessive value of the variable related to the horizontal velocity, a protection which was provided for several other variables of the alignment software. When taking this design decision, it was not analyzed or fully understood which values this particular variable might assume when the alignment software was allowed to operate after lift-off.

Below is presented the Ada program of the inertial reference system:

`
...
declare
  vertical_veloc_sensor: float;
  horizontal_veloc_sensor: float;
  vertical_veloc_bias: integer;
  horizontal_veloc_bias: integer;
  ...
begin
  declare
    pragma suppress(numeric_error, horizontal_veloc_bias);
  begin
    sensor_get(vertical_veloc_sensor);
    sensor_get(horizontal_veloc_sensor);
    vertical_veloc_bias := integer(vertical_veloc_sensor);
    horizontal_veloc_bias := integer(horizontal_veloc_sensor);
    ...
  exception
    when numeric_error => calculate_vertical_veloc();
    when others => use_irs1();
  end;
end irs2;
`

Although one may criticize the Ada exception mechanism, it could have been used here to catch the exception. In fact, quoting the report:
“Not all the conversions were protected because a maximum workload target of 80% had been set for the SRI computer. To determine the vulnerability of unprotected code, an analysis was performed on every operation which could give rise to an ... operand error. This led to protection being added to four of seven variables... in the Ada code.” However, three of the variables were left unprotected. In other words, the potential problem of failed arithmetic conversions was recognized. Unfortunately, the fatal exception was among the three that were not monitored, not the four that were.

In Ariane 4 flights using the same type of inertial reference system there has been no such failure because the trajectory during the first 40 seconds of flight was such that the particular variable related to horizontal velocity could not reach, with an adequate operational margin, a value beyond the limit present in the software.

Ariane 5 had a high initial acceleration and a trajectory which leaded to a build-up of horizontal velocity which was five times more rapid than for Ariane 4. The higher horizontal velocity of Ariane 5 was generated within a certain function having a 40-second timeframe, the excessive value caused the inertial system computers to end operation.

Here, another question arises: What was the reason to decide to run a function for 40 second? Answer: one extra absurdity. The engineers in charge chose long ago, in an earlier version of the Ariane, to leave this function running for the first 40 seconds of flight, as a "special feature" meant to make it easy to restart the system in the event of a brief hold in the countdown. This “feature” resulted to be the calculation containing the bug, which shut down the guidance system, which confused the on-board computer, which forced the rocket off course and actually served no purpose once the rocket was in the air. Its only responsibility was to align the system before launch. So it should have been turned off in order to get things done properly. But the programmers had decided that this particular velocity figure would never be large enough to cause trouble. Most probably, the fact that Ariane 5 was a faster rocket than Ariane 4 wasn’t taken into account. In consequence, this situation generated a major subject for the whole world to discuss about.

So, back to the main idea, this is the sequence of facts that leaded to the disaster: the steering was controlled by the on-board computer, which mistakenly thought the rocket needed a course change because of numbers coming from the inertial reference system. The numbers looked like flight data, bizarre and impossible flight data, but were actually a diagnostic error message. The guidance system had in fact shut down.

This shutdown occurred 36.7 seconds after launch, when the guidance system's own computer tried to convert one piece of data, the sideways velocity of the rocket, from a 64-bit format to a 16-bit format. The number was too big, and an overflow error resulted. There was no explicit exception handler to catch the exception, so it followed the usual fate of uncaught exceptions. When the guidance system shut down, it passed control to an identical, redundant unit, which was there to provide backup in case of just such a failure. But the second unit had failed in the identical manner a few milliseconds before. And why not? It was running, of course, the same software.

Enough words for now, let’s take a look at the Ariane 5 launching itself:

[VIDEO]

A few more things about the bug that brought so much attention to the community: it belongs to a species that has existed since the first computer programmers realized they could store numbers as sequences of bits, atoms of data, ones and zeroes: 1011010100010001101001…. A bug like this might crash a spreadsheet or word processor on a bad day, but instead it crushed one of the most expensive rockets built on that period. Ironic, isn’t it?

The self-destruction of the launcher occurred near to the launch pad, at an altitude of approximately 3700 m. Therefore, all the launcher remains fell back onto the ground, scattered over an area of approximately 12 km2 east of the launch pad. Recovery of material proved difficult, however, since this area is nearly all mangrove swamp or savanna.

Nevertheless, it was possible to retrieve from the remains the two Inertial Reference Systems. Of particular interest was the one which had worked in active mode and stopped functioning last, and for which, therefore, certain information was not available in the telemetry data (provision for transmission to ground of this information was limited to whichever of the two units might fail first). The results of the examination of this unit were very helpful to the analysis of the failure sequence.

One item that was fully qualified after the very unfortunate explosion of the launcher was the safety system, as well as its forecasts and computing models (remains impact zone, cloud dispersion model, absence of air toxicity beyond the safety limits). No gaseous pollution at ground level was detected by any of the measuring instruments outside the launch area. The cloud produced by the explosion and the plume of exhaust gases immediately moved parallel to the coast, and were monitored by helicopters until three hours after the accident, by which time they were several kilometers off the coast and dissipating gradually.

So, analyzing the whole situation, somebody could ask why was the exception not monitored? Was that a design error? The analysis revealed that overflow could not occur. Was the analysis wrong? No! It was right for the Ariane 4 trajectory. For Ariane 5, with other trajectory parameters, it did not hold any more.

What about an implementation error? Although somebody may criticize the removal of a protection to achieve more performance (the 80% workload target), it was justified by the theoretical analysis. To engineer is to make compromises. If you have proved that a condition cannot happen, you are entitled not to check for it. If every program checked for all possible and impossible events, no useful instruction would ever get executed!

Then what was the source of the problem? Most probably, it was a reuse error. The SRI (Inertial Reference System) horizontal bias module was reused from a 10-year-old software, the software from Ariane 4. But this is not the full story, the truly unacceptable part was the absence of any kind of precise specification associated with a reusable module. The requirement that the horizontal bias should fit on 16 bits was in fact stated in an obscure part of a document. But in the code itself it was nowhere to be found! From the principle of Design by Contract, we know that in order to construct reliable software, any participant element that has such a fundamental constraint should state it explicitly, as part of a mechanism present in the programming language. Does this mean that the crash would automatically have been avoided if the mission used a language and method supporting built-in assertions and Design by Contract? Although it is always risky to draw such after-the-fact conclusions, the answer is probably yes.



The Europeans hoped to launch a new Ariane 5 next spring, this time with a newly designated "software architect" who will oversee a process of more intensive and realistic ground simulation. Simulation is the great hope of software debuggers everywhere, though it can never anticipate every feature of real life. "Very tiny details can have terrible consequences," said Jacques Durand, head of the project, in Paris. "That's not surprising, especially in a complex software system such as this is."


So, after all this talking, what is the lesson for us, engineers, to learn?

Don’t reuse code you are not sure about and even if you truly believe in it- test it again!

The Ariane 5 mistake shows clearly that naive hopes are doomed to produce results far worse than a traditional, reuse-less software process. To attempt to reuse software without any kind of additional verification (assertions) is to invite failures of potentially disastrous consequences. The next time around, will it only be an empty payload, however expensive, or will it be human lives?

For reuse to be effective, Design by Contract is a requirement. Without a precise specification attached to each reusable component like precondition, postcondition or invariant, no one can trust a supposedly reusable component.

