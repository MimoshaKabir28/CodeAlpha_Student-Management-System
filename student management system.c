#include<stdio.h>

struct Student{
    int id;
    char name[50];
    float cgpa;
};

void addStudent(){
    struct Student student;
    FILE *file=fopen("students.dat", "ab");

    if (file==NULL){
        printf("Error opening file.\n");
        return;
    }

    printf("\nEnter student ID: ");
    scanf("%d",&student.id);

    printf("Enter student name: ");
    scanf(" %[^\n]",student.name);

    printf("Enter CGPA: ");
    scanf("%f",&student.cgpa);

    fwrite(&student,sizeof(student),1,file);
    fclose(file);

    printf("Student added successfully!\n");
}

void displayStudents(){
    struct Student student;
    FILE *file=fopen("students.dat","rb");

    if (file==NULL){
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n===== Student Records =====\n");

    while (fread(&student,sizeof(student),1,file)==1){
        printf("ID    : %d\n", student.id);
        printf("Name  : %s\n", student.name);
        printf("CGPA  : %.2f\n", student.cgpa);
        printf("---------------------------\n");
    }

    fclose(file);
}

void searchStudent(){
    struct Student student;
    int id, found=0;

    FILE *file=fopen("students.dat","rb");

    if (file==NULL){
        printf("\nNo student records found.\n");
        return;
    }

    printf("\nEnter student ID to search: ");
    scanf("%d",&id);

    while (fread(&student,sizeof(student),1,file)==1){
        if (student.id==id){
            printf("\nStudent found!\n");
            printf("ID    : %d\n", student.id);
            printf("Name  : %s\n", student.name);
            printf("CGPA  : %.2f\n", student.cgpa);

            found=1;
            break;
        }
    }

    fclose(file);

    if (!found){
        printf("Student not found.\n");
    }
}

void updateStudent(){
    struct Student student;
    int id,found=0;

    FILE *file=fopen("students.dat","rb+");

    if (file==NULL){
        printf("\nNo student records found.\n");
        return;
    }

    printf("\nEnter student ID to update: ");
    scanf("%d",&id);

    while (fread(&student,sizeof(student),1,file)==1){
        if (student.id==id) {

            printf("Enter new name: ");
            scanf("%[^\n]",student.name);

            printf("Enter new CGPA: ");
            scanf("%f",&student.cgpa);

            fseek(file,-sizeof(student),SEEK_CUR);
            fwrite(&student,sizeof(student),1,file);

            printf("Student updated successfully!\n");
            found=1;
            break;
        }
    }

    fclose(file);

    if (!found){
        printf("Student not found.\n");
    }
}

void deleteStudent(){
    struct Student student;
    int id,found=0;

    FILE *file=fopen("students.dat", "rb");
    FILE *temp=fopen("temp.dat", "wb");

    if (file == NULL || temp == NULL){
        printf("\nError opening file.\n");

        if (file != NULL)
            fclose(file);

        if (temp != NULL)
            fclose(temp);

        return;
    }

    printf("\nEnter student ID to delete: ");
    scanf("%d",&id);

    while (fread(&student,sizeof(student),1,file) == 1){

        if (student.id==id){
            found=1;
        } else{
            fwrite(&student,sizeof(student),1,temp);
        }
    }

    fclose(file);
    fclose(temp);

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found){
        printf("Student deleted successfully!\n");
    } else{
        printf("Student not found.\n");
    }
}

int main(){
    int choice;

    do {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice){

            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice!=6);

    return 0;
}