   M S B A M L   `   `   `  ����C  ?ToDoList, Version=1.2.0.0, Culture=neutral, PublicKeyToken=null)clr-namespace:ToDoListAppToDoListApp  5   	       ToDoListApp.MainWindow   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   *todoclr-namespace:ToDoListApp     5   	   -   5          � Title$  To Do:��5   	    � SizeToContent$ Width=�6   $	��220��6.    � 
ResizeMode$ CanMinimize=�6U    � WindowStyle$ 
ToolWindow=�6n    � Icon$" /ToDoList;component/todo.ico��6�   $	��463��6�    � 	Resources 5         itemMenu��%�   &	        �� 5   
   .@�5      m� -   5        $��_Edit��5      6&   m� 5	      -   5        $��_Mark as done��5	      6.   �� 5
      6   m� 5      -   5        $��_Delete��5      6(   5      5      .��5      � $��0,0,29,0q�6    � RowDefinitions 5   
   �� 5      $��1* �6   �� 5      $
��Auto �6   �� 5      $
��Auto �6    � ColumnDefinitions 5   
   �� 5      $
��Auto �6   �� 5      $��1* �6   �� 5      $
��Auto �6   .+�5   
   �� -   5        $��lvToDo��5      $��Stretch=�6!   $��0��6>   $��3��6K    � ContextMenu# [  5   >   $
��Left=�6�   $	��457��6�   $��	0,0,-29,0q�6�   ��6f   �� 	 �� Path$	 Items�6�   �� 5   
   -   5        $��txtItemDesc��5      $��1��6%   $��1��62   $��0,0,86,0q�6h   �� 5   
   -   5        $��btnAdd��5   a   $��Add new task��6   $��1��6(   $��right=�65   $��1��6Q   $��2��6�   $	��110��6�   $��	0,0,-29,0q�6�   �� 5   
   -   5        
 ��Name$
 chkShowDone��5      $��3��6)   $��2��6=   $��Show done tasks��6J   $��347,5,-223,0q�6�    d� 	IsChecked 6d   �� $	 ShowDoneItems� �� Mode$ TwoWay=�6�   5      5      