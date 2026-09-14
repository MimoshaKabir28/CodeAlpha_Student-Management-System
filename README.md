
# CodeAlpha Student Management System

A student management system developed using C programming as part of the CodeAlpha C Programming Internship.

## Project Overview

This project is a menu-driven C program that allows users to manage student records. It provides options to add, display, search, update, and delete student information.

## Features

* Add Student
* Display Students
* Search Student
* Update Student
* Delete Student
* Permanent data storage using file handling
* Menu-driven interface

## Concepts Used

* C Programming
* Structures
* Functions
* File Handling
* `fopen()` for opening files
* `fread()` for reading student records
* `fwrite()` for saving student records
* `fseek()` for updating records
* `remove()` and `rename()` for deleting records
* `switch-case` for menu selection
* Conditional statements

## How the Program Works

1. The user selects an option from the main menu.
2. The user can add a student by entering the ID, name, and CGPA.
3. Student information is stored in a file.
4. The user can display all stored student records.
5. The user can search for a student using the student ID.
6. The user can update a student's name and CGPA.
7. The user can delete a student record using the student ID.
8. The user can exit the program from the main menu.

## Example

```text
===== Student Management System =====
1. Add Student
2. Display Students
3. Search Student
4. Update Student
5. Delete Student
6. Exit

Enter your choice: 1

Enter student ID: 101
Enter student name: Ayman
Enter CGPA: 3.75

Student added successfully!
```

## Technology Used

**Language:** C

**Development Environment:** Visual Studio Code

## Internship Task

**CodeAlpha C Programming Internship — Task 3: Student Management System**
