Laboratory Work Nr.3
====================
Title:
------
Basics of Working with Mouse. GDI Primitives. Bezier Curve.
------------
Contents:

•	Mouse

•	Device context

•	GDI Primitives

•	Line

•	Curve

•	Plane

•	Bitmap image

•	Bezier curve

Completed Mandatory Objectives:
--------------------
•	Draw few lines of different colors and weights

•	Draw a Bezier curve

•	Draw few plane objects (ex. circle, square, pie, polygon...) of different colors, weights, filled and not

•	Draw 2 different objects using mouse

Objectives With Points:
----------------------
•	Draw a custom bitmap image (1 pt)

•	Add a switch (button, select list...) that will change mouse ability to draw objects (2 pt)

•	Draw a Bezier curve using mouse (1 pt)

•	Fill an object with a gradient (1 pt)

•	Delete objects using mouse clicking (2 pt)

•	Use mouse as an eraser of an adjustable width (1 pt)

Creation steps of the app:
--------------------------
For this laboratory work, I found very useful Charles Petzold's book- *"Programming Windows"*, chapters 5 and 7 from the first section. Reading it helped me in understanding the main features for working with the mouse. Of course, the precious help of [http://msdn.microsoft.com](http://msdn.microsoft.com) was unreplaceble. Also, some dilemmas were solved by [http://stackoverflow.com](http://http://stackoverflow.com). 

For a better understanding of my app, bellow I'll present its mockup:

 ![mockup](https://raw.github.com/TUM-FAF/FAF-121-Gusan-Gina/master/WP/Lab2_WP/screenshots/mockup.png)

Features and functionality:
---------------------------
1.	I’ve started with 3 group boxes that split in branches the tools of my application:

	•	Style

	•	Color

	•	Tools

2.	The “Fill” checkbox is used when you want to fill an object( ex.: ellipse, polygon) with a gradient.

3.	The “Stroke” label gives us the possibility to choose a value that will represent the width of the line or the object you want to draw.

4.	The “Eraser” tool is used for clearing a portion of the drawing area using the mouse. Its dimensions also can be defined by choosing a corresponding value.

5.	In the next group box, can be seen two labels that allow us to view the color chosen for filling an object and for drawing a line of a particular width.

6.	Next, you see the RGB set of gradients,  that includes all the possible colors to choose from.

7.	The first tool from the third group box is the “Pen” tool, which can be used for drawing continuous lines, having the stroke 1. We also can define a specific color or change the stroke for those lines.

8.	The “Line” tool is used for drawing straight lines. This is done by setting the starting point and the ending point.

9.	The “Ellipse” tool is used for drawing ellipses. This thing is done by left-clicking on the drawing area and then dragging and dropping the cursor.

10.	The “Polygon” tool is used to draw different squares or rectangles, by left-clicking the mouse to establish the first point, drag-and-drop the mouse to define the last point.

11.	The “Bezier” tool is used to draw Bezier curves. You can select the first point by left-clicking the mouse and then drag-and drop it; the second point is selected by right-clicking the mouse and also drag-and-drop it.

All the tools have the possibility of choosing different colors for filling the objects you are going to draw. You can provide different dimensions for the width of the lines and different colors for them.

12.	The drawing area is the place where all the paintings are done. Also here you can delete an object (ellipse or polygon) by right-clicking on it.

13.	For the beauty of the application, I’ve added  a bitmap image on the bottom of the drawing area.


Here are some screenshots of the application:

![main](https://raw.github.com/TUM-FAF/FAF-121-Gusan-Gina/master/WP/Lab2_WP/screenshots/main.png)

![about_dialogbox](https://raw.github.com/TUM-FAF/FAF-121-Gusan-Gina/master/WP/Lab2_WP/screenshots/about_dialogbox.png)

![background_dialogbox](https://raw.github.com/TUM-FAF/FAF-121-Gusan-Gina/master/WP/Lab2_WP/screenshots/background_dialogbox.png)
 

Conclusion:
-----------

In this laboratory work we had to build an application similar to Paint. Doing it helped me discover some new features of Windows Programming and apply them into my program. 

I’ve found out how to work with the mouse and I’ve understood how it manipulates graphical data. It was a little bit difficult to deal with all kind of lines especially Bezier curves, but finally I’ve got the main idea.

I’ve also learned about bitmap images and I found them very useful for the beauty of the interface. This application provides a lot of features based on mouse clicks, fact that makes a user feel confident using it because it is pretty similar with standard Windows apps.






