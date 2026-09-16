#include <stdio.h>
int main()
{     int n, i;     long long fact = 1;     printf("Enter a number: ");
}
nano factorial.c
mkdir linux_task2
cd linux_task2
touch source.txt data.txt notes.txt
nano source.txt
mkdir backup
ls backup
cp source.txt backup/
ls backup
cp data.txt backup/data_backup.txt
ls backup
mv notes.txt backup/
ls backup
mv source.txt original.txt
ls
ls -R
tree
mkdir linux_task1
cd linux_task1
touch file1.txt file2.txt file3.txt file4.txt file5.txt
ls
ls -l
echo "Linux is an operating system." > file1.txt
echo "I am learning Linux commands." >> file1.txt
cat file1.txt
rm file5.txt
ls
mkdir linux_task3
cd linux_task3
touch students.txt
ls
nano students.txt
cat students.txt
head -n 5 students.txt
head -n 10 students.txt
tail -n 5 students.txt
mkdir organization
cd organization
touch file1.txt file2.txt file3.txt image1.jpg image2.jpg
ls
mkdir documents
mkdir images
ls
mv *.txt documents/
ls documents
mv *.jpg images/
ls images
ls documents
ls images
mv documents/file1.txt documents/notes.txt
ls documents
mv images/image1.jpg images/photo.jpg
ls images
tree
mkdir project
cd project
mkdir -p source/c source/python docs backup
ls
ls -R
touch source/c/file1.c source/c/file2.c source/c/file3.c
ls source/c
touch source/python/file1.py source/python/file2.py
ls source/python
ls -R
rmdir backup
ls
mkdir backup
touch backup/test.txt
ls backup
rmdir backup
rm backup/test.txt
ls backup
rmdir backup
ls
tree
ls
cd ~
mkdir 2520030349_Practical
cd BotsCreate_Practical
ls - d */
ls BotsCreate_Practical 
cd BotsCreate_OSSP
ls
cd BotsCreate_Practical
pwd
ls
nano factorial.c
ls
gcc factorial.c -o factorial
ls 
./factorial 6
./factorial 4
./factorial 8
nano parent.c
ls
gcc parent.c -o parent
ls
./parent 
cd ~/BotsCreate_OSSP
tree
mkdir -p ~/myshell-project
cd~/myshell-project
cd ~/myshell-project
cat > skill1_shell.c << 'EOF'
#include <stdio.h>
#include <string.h>
int main() {
    char command[100];
    while (1) {
        // Display prompt
        printf("myshell> ");
        fflush(stdout);
        // Read user input
        fgets(command, sizeof(command), stdin);
        // Remove newline
        command[strcspn(command, "\n")] = '\0';
        // Check exit condition
        if (strcmp(command, "exit") == 0) {
            printf("Exiting shell...\n");
            break;
        }
        // Process command
        printf("You entered: %s\n", command);
    }
    return 0;
}
EOF

cat > skill2_shell.c << 'EOF'
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX_INPUT 100
/* Process the entered command */
void processCommand(char *command) {
    if (strcmp(command, "hello") == 0)
        printf("Hello! Welcome to MyShell.\n");
    else if (strcmp(command, "help") == 0) {
        printf("\nAvailable commands:\n");
        printf("  hello  - Display greeting\n");
        printf("  help   - Display available commands\n");
        printf("  exit   - Exit the shell\n");
    }
    else if (strlen(command) == 0) {
        /* Do nothing for empty input */
    }
    else
        printf("Unknown command: %s\n", command);
}
int main(){
    char buffer[MAX_INPUT];
    while (1) {
        printf("myshell> ");
        fflush(stdout);
        fgets(buffer, sizeof(buffer), stdin);
        // Remove newline
        buffer[strcspn(buffer, "\n")] = '\0';
        // Check exit condition
        if (strcmp(buffer, "exit") == 0) {
            printf("Exiting shell...\n");
            break;
        }
        else {
            processCommand(buffer);
            fflush(stdout);
        }
    }
    return 0;
}
EOF

git init 
git config --global user.name "rohinitanmayi"
git config --global user.email "rohinitanmayidusi@gmail.com"
git add skill1_shell.c skill2_shell.c
git commit -m "Add Skill 1 and Skill 2: MyShell command loop and command handling"
git branch -M main 
git remote add origin https://github.com/rohinitanmayi/BotsCreate_OSSP-.git
git push -u origin main 
git push -u origin main  
git pull origin main --allow-unrelated-histories
git pull origin main --allow-unrelated-histories --no-rebase
git push -u origin main
nano infinite loop.c
mv "loop.c" infinite_loop.c
ls
rm -r infinite
nano infinite_loop.c
gcc infinite_loop.c -o infinite_loop
./infinite_loop
nano cpuscheduling.c
sudo ls 
nano cspr.c
