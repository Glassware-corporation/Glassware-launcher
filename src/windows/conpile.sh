# UNUSED

clear
echo "jake.INC (C) 2022"
echo '\033[31mNITP -  Not In The Program \033[39m'
echo "Compiling..."
g++ $1.cpp -o $2
echo runing $2
echo =====start=====
echo '\033[34m'
./$2
exitCode=$?
echo '\033[39m'
echo =====end=====
echo "Done"
echo "exit code: $exitCode"
rm $2
echo "Deleted $2"
exit 0
