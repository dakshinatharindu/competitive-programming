# Project Overview
The Broomstick Management System is a fictional system used to manage flying broomsticks manufactured and registered every year in the Ministry of Magic Office. Every broomstick registered in the system has a uniquely identified license plate number with 4 characters consisting of A-Z letters 0-9 numbers. The owner of a broomstick registered in the system is required to pay registration and management fee of 4 Galleons annually. Also, a user can customize the license plate number by their own if it is already not in the system. However, there will be an additional cost of 3 Galleons incurred in customized plate annually.

The Broomstick Management System utilizes a Red-Black Tree as its underlying data structure. It is built using C++ from the scratch without using any C++ STL libraries. The following section of the report consist in-detail explanation of project structure, program structure and function prototype.

# Project Structure
The project consists of the following files:
- `main.cpp`: This is the main file which contains the main function. It handles user input and output, and interacts with the Red-Black Tree to perform various operations.
- `red_black_tree.h`: This header file contains the definition of the Red-Black Tree class, including its member functions and data members.
- `red_black_tree.cpp`: This file contains the implementation of the Red-Black Tree class. It includes the logic for inserting, deleting, searching, and balancing the tree.

# Program Structure
The program is structured as follows:
1. **Node Structure**
2. **Red-Black Tree Class**
3. **Main Function**

## 1. Node Structure
The `Node` structure represents a single node in the Red-Black Tree. It contains the following members:
- `plate_number`: A string representing the license plate number of the broomstick.
- `owner_name`: A string representing the name of the owner of the broomstick.
- `color`: An integer representing the color of the node (0 for Red, 1 for Black).
- `left`: A pointer to the left child of the node.
- `right`: A pointer to the right child of the node.
- `parent`: A pointer to the parent node.

It also includes a constructor to initialize the node with a given license plate number and owner name. The color is set to Red by default when a new node is created.

### 2. Red-Black Tree Class
The `RedBlackTree` class represents the Red-Black Tree itself. It contains the following members and methods:
- **Data Members:**
  - `root`: A pointer to the root node of the tree.
  - `totalRevenur` : An integer to keep track of the total revenue generated from the registration and management fees.

- **Member Functions:**
    