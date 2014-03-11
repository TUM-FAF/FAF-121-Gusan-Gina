Laboratory Work Nr.2
====================
Title:
-----
Advanced Form Elements. Child Windowses. Basics of Working With Keyboard.
------------
Contents:

•	The Keyboard

•	Child Window Controls

•	Scroll Bar

•	Listbox

•	Menus and Other Resources

•	Dialog Boxes

Completed mandatory Objectives:
--------------------
•Display a dialog box on some event (ex. on clicking some button)

•Add a system menu to your application with at least 3 items (add actions to that items)

•Add a scroll bar that will change any visible parameter of any other element (color of a text)

•Hook keyboard input. Add 2 custom events for 2 different keyboard combinations (ex. change window background on ctrl+space)

Objectives With Points:
----------------------
•Add a listbox and attach some events when any element is accessed (clicked) (2 pt)

•Add 2 scroll bars that will manage main window size or position (1 pt)

•Customize your application by adding an icon and using different cursor in application (1 pt)

Creation steps of the app:
--------------------------
For this laboratory work, I found very useful Charles Petzold's book- *"Programming Windows"*, chapters 6, 9, 10 and 11 from the first section. Reading it helped me in understanding the main features for working with scroll bars, ListBoxes, menus and keyboard. Of course, the precious help of [http://msdn.microsoft.com](http://msdn.microsoft.com) was unreplaceble. Also, some dilemmas were solved by [http://stackoverflow.com](http://http://stackoverflow.com). 

For a better understanding of my app, bellow I'll present its mockup:

 ![mockup](https://raw.github.com/TUM-FAF/FAF-121-Gusan-Gina/master/WP/Lab2_WP/screenshots/mockup.png)

Features and functionality:
---------------------------
1.	An Edit Box for adding text;

2.	An List Box for output text- at double clicking an item, a message box is displayed.

3.	Two scroll bars used to change the width and the height of the window;

4.	One button to add an item to the ListBox;

5.	One button to remove an item from the ListBox;

6.	One button to clear all the items from the ListBox; 

7.	Three scroll bars located in the dialog box responsible for the background color;

8.	Four hotkeys for moving the window on the screen:

•	Ctrl+F1- Move window right

•	Ctrl+F2- Move window left

•	Ctrl+F3- Move window down

•	Ctrl+F4- Move window up;

9.	A personalized icon for my application;

10.	A personalized cursor for my application;

11.	A system menu with 3 items: File, View, Help;

Here are some screenshots of the application:

![main](https://raw.github.com/TUM-FAF/FAF-121-Gusan-Gina/master/WP/Lab2_WP/screenshots/main.png)

![about_dialogbox](https://raw.github.com/TUM-FAF/FAF-121-Gusan-Gina/master/WP/Lab2_WP/screenshots/about_dialogbox.png)

![background_dialogbox](https://raw.github.com/TUM-FAF/FAF-121-Gusan-Gina/master/WP/Lab2_WP/screenshots/background_dialogbox.png)
 
**Something about the MENU:** 

• Two dialog boxes: one modal and one modeless;

•	From the File menu, we can exit the program;

•	From the Properties menu, we can open the dialog box consisting of the three scrollbars that manage the background color;

•	From the Help menu, we can open the last dialog box that includes some information about the application.

Conclusion:
-----------

Doing this laboratory work helped me discover some new features of Windows Programming and apply them into my own program. I’ve learned how to work with different types of dialog boxes and how to create an system menu. For the functionality of my dialog boxes I had to implement two more procedures, create resource files for them and also use the WM_COMMAND message to display them on the screen. . Creating the menu was done by using the CreateMenu() and CreatePopupMenu() functions. 
One of the most difficult things to do in this lab was to work with scroll bars. Because scroll bars don’t  send WM_COMMAND messages to the parent window, I had to create WM_VSCROLL and WM_HSCROLL messages, just like window scroll bars. When processing the scroll bar messages, I could differentiate between window scroll bars and scroll bar controls by the lParam parameter. It is  0 for window scroll bars and the scroll bar window handle for scroll bar controls. I set the range and position of my scroll bar controls with the same calls used for window scroll bars: SetScrollRange(), SetScrollInfo(), SetScrollPos().The only difference is that window scroll bars use a handle to the main window as the first parameter and SB_VERT or SB_HORZ as the second parameter.

Also, I’ve added 4 custom events for 4 different keyboard combinations, using the GetKeyState function that determines if the Ctrl button is pressed. I used GetKeyState with the virtual key codes VK_CONTROL and  VK_F1, VK_F2, VK_F3, VK_F4 to move the window.






