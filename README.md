# EsepDataProcessing

Steps:
1) Clone the project
2) Once project is cloned, go to the project (ideally on VS Code)
3) Run the following command on the terminal (make sure you are still on the main project directory):
           ./dbRun
   This command will run the program. If the command doesn't work, run the following command "make" (without the quotation marks) and it will recompile the code so that you can run "./dbRun" again.
4) Then, you will be met with a prompt list of options. The options are labeled properly so that you understand what function it may be calling, etc. The 7th option, called "Sample Run", is a run of the commands from the code figures given on the assignment document.
5) To exit the program, enter the number 8.
6) To see the actual code, visit "DB.cpp" file, which has the main database function definitions. The file "DB.h" is used for declaring the class and its functions, while the "main.cpp" file is used for testing. The "DB.cpp" file is the one needed for grading.

How this assignment can be modified

Having clearer instructions on the testing/running aspect of the project would be better. I am unsure of how the graders would run the project (would they take the class files and run their own testing file, or would they want us to create a user interface), so I ended up creating the user interface (list of options), and the sample run just to be safe. Additionally, a function to reset the database completely (erase all data) should have been implemented in the assignment document. I added a reset function for testing reasons but having it officially be part of the assignment would have been good.
