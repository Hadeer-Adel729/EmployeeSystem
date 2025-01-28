# Employee Management System in C
This project is a simple Employee Management System implemented in C. It allows users to store new employees and display all employees using a menu-driven interface. The menu navigation is done using arrow keys, and the user can select options to add new employees, display existing employees, or exit the program.

## Features
- Add New Employees: Users can input details such as employee name, code, salary, bonus, and deductions. The system calculates the net salary automatically.

- Display Employees: Users can view the details of all stored employees, including their name, code, and net salary.

- Menu Navigation: The program uses arrow keys (up and down) to navigate through the menu options and the Enter key to select an option.

- Dynamic Memory Allocation: The program dynamically allocates memory for storing employee data, ensuring efficient memory usage.

##Code Structure
The code is structured into several functions, each responsible for a specific task:

- New(): Displays the menu with the "New" option highlighted.

- Display(): Displays the menu with the "Display" option highlighted.

- Exit(): Displays the menu with the "Exit" option highlighted.

- homeScreen(): Displays a prompt instructing the user to press Enter to access the menu.

- take_str_input(): Reads a string input from the user.

- readEmployee(): Reads employee details from the user and stores them in the dynamically allocated memory.

- displayEmployee(): Displays the details of all stored employees.

- arrow_up(): Handles the up arrow key press to navigate the menu.

- arrow_down(): Handles the down arrow key press to navigate the menu.

- enter_key(): Handles the Enter key press to select a menu option.

##How to Use
- Compile the Code: Use a C compiler to compile the code.
  
- Run the Program: Execute the compiled program.
  
- Navigate the Menu:

   - Use the Up and Down arrow keys to navigate through the menu options.

   - Press Enter to select an option.

  - Follow the on-screen instructions to add new employees or display existing ones.

  - Exit the Program: Select the "Exit" option from the menu to terminate the program.

