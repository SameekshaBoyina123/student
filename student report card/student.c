
// Define a structure to hold student data
struct Student {
    char name[50];
    int roll;
    float marks[5]; // marks for 5 subjects
    float total;
    float average;
    char grade;
};

// Function to calculate total, average and grade
void calculateResults(struct Student *s) {
    s->total = 0;
    for (int i = 0; i < 5; i++) {
        s->total += s->marks[i];
    }
    s->average = s->total / 5.0;

    // Grade assignment
    if (s->average >= 90)
        s->grade = 'A';
    else if (s->average >= 75)
        s->grade = 'B';
    else if (s->average >= 60)
        s->grade = 'C';
    else if (s->average >= 40)
        s->grade = 'D';
    else
        s->grade = 'F';
}

// Function to print report card
void printReportCard(struct Student s) {
    printf("\n===== STUDENT REPORT CARD =====\n");
    printf("Name      : %s\n", s.name);
    printf("Roll No   : %d\n", s.roll);
    printf("Marks     :\n");
    for (int i = 0; i < 5; i++) {
        printf("  Subject %d: %.2f\n", i + 1, s.marks[i]);
    }
    printf("Total     : %.2f\n", s.total);
    printf("Average   : %.2f\n", s.average);
    printf("Grade     : %c\n", s.grade);
    printf("===============================\n");
}

int main() {
    struct Student s;

    // Use getchar to flush newline after scanf
    printf("Enter roll number: ");
    scanf("%d", &s.roll);
    getchar(); // consume leftover newline character

    printf("Enter student name: ");
    fgets(s.name, sizeof(s.name));
    s.name[strcspn(s.name, "\n")] = '\0'; // remove newline

    printf("Enter marks for 5 subjects:\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &s.marks[i]);
    }

    calculateResults(&s);
    printReportCard(s);

    return 0;
}
