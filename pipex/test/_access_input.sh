#!bin/bash

line1="======================================================================================="
line2="---------------------------------------------------------------------------------------"
GREEN="\033[38;2;57;181;74m"
RED="\033[38;2;222;56;43m"
BLUE="\033[38;2;34;183;235m"
YELLOW="\033[38;2;255;176;0m"
PURPLE="\033[38;2;255;105;180m"
WHITE="\033[1;37m"
RESET="\033[0m"

echo "Checking access rights for input file" > z_log_access_input.txt.txt
echo "" >> z_log_access_input.txt.txt
echo $line1>> z_log_access_input.txt.txt

echo "TEST 1 - READ ONLY FILE - read_only.txt" >> z_log_access_input.txt.txt
file_input="read_only.txt"
echo $line2 >> z_log_access_input.txt.txt
echo "Shell output:" >> z_log_access_input.txt.txt
< $file_input grep hello | wc -c >> z_log_access_input.txt.txt 
echo $line2 >> z_log_access_input.txt.txt
echo "Pipex output:" >> z_log_access_input.txt.txt
../bin/pipex $file_input "grep hello" "wc -c" z_test.txt >> z_log_access_input.txt.txt 
echo $line1>> z_log_access_input.txt.txt
echo "" >> z_log_access_input.txt.txt
echo $line1>> z_log_access_input.txt.txt

echo "TEST 2 - No executable access - no_exec_access.txt" >> z_log_access_input.txt.txt
file_input="no_exec_access.txt"
echo $line2 >> z_log_access_input.txt.txt
echo "Shell output:" >> z_log_access_input.txt.txt
< $file_input grep hello | wc -c >> z_log_access_input.txt.txt 
echo $line2 >> z_log_access_input.txt.txt
echo "Pipex output:" >> z_log_access_input.txt.txt
../bin/pipex $file_input "grep hello" "wc -c" z_test.txt >> z_log_access_input.txt.txt 
echo $line1>> z_log_access_input.txt.txt
echo "" >> z_log_access_input.txt.txt
echo $line1>> z_log_access_input.txt.txt

touch no_read.txt
cat "HELLOABVVD hello" >> no_read.txt
chmod 333 no_read.txt
echo "TEST 3 - No read - no_read.txt" >> z_log_access_input.txt.txt
file_input="no_read.txt"
echo $line2 >> z_log_access_input.txt.txt
echo "Shell output:" >> z_log_access_input.txt.txt
< $file_input grep hello | wc -c >> z_log_access_input.txt.txt 
echo $line2 >> z_log_access_input.txt.txt
echo "Pipex output:" >> z_log_access_input.txt.txt
../bin/pipex $file_input "grep hello" "wc -c" z_test.txt >> z_log_access_input.txt.txt 
echo $line1>> z_log_access_input.txt.txt
echo "" >> z_log_access_input.txt.txt
echo $line1>> z_log_access_input.txt.txt
rm -f no_read.txt


echo "TEST 4 - FILE does not exist" >> z_log_access_input.txt.txt
file_input="no_existing_file"
echo $line2 >> z_log_access_input.txt.txt
echo "Shell output:" >> z_log_access_input.txt.txt
< $file_input grep hello | wc -c >> z_log_access_input.txt.txt 
echo $line2 >> z_log_access_input.txt.txt
echo "Pipex output:" >> z_log_access_input.txt.txt
../bin/pipex $file_input "grep hello" "wc -c" z_test.txt >> z_log_access_input.txt.txt 
echo $line1>> z_log_access_input.txt.txt
echo "" >> z_log_access_input.txt.txt
echo $line1>> z_log_access_input.txt.txt

