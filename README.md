# OSContEvalC
OS Project: Command-Line UI
Team Number 8 
Members
Baindla Goutham			- CS19B006
Amasa Yaswanth			- CS19B002
Chejarla Venkata Sandeep	- CS19B009
Gagan Hegde			- CS19B015


#Aim
Creation of command line UI to display 4x4 grid data for 4 students vs 4 faculty. Each data in each cell ranges between 0 and 9, and the fifth column shows the total of each row.


#Characteristic expected:
Show the output in terminal raw mode, with user interaction as discussed in class. Especially highlight the current cell appropriately and visually
Provide user navigation only to 16 cells inside the grid using four arrow keys
Data entry: Upon keying in "Enter", the cell goes blank and shows a blinking cursor to indicate data-entry. Upon entering valid input (do sanity check), and hitting "Enter" save the data and update the corresponding total. On the other hand, upon entering input and hitting "Esc" key, show the previous data and come out of data entry mode and highlight the current cell as usual


#Sources
As advised in class, one could use existing text-editors or any other editor software source code to design the base of the project.
We used a text-editor called ‘Kilo’ developed by Salvatore Sanfilippo (GitHub: ‘antirez’). It is a simple text-editor with no dependencies. We removed parts of the code we did not require like commands and other extra features.
The GitHub repository for the above-mentioned text-editor is https://github.com/antirez/kilo


#Our project
As directed, ours is a simple grid-based text editor that allows a user to edit the values of 16 cells (4 rows and 4 columns). In addition to this, there is a row with faculty names and a row with student names which cannot be navigated into. There is a status bar at the bottom to show the sum and the row number along with column number.


#Tools
We used Xcode to develop the code on a Mac computer.
