import time
import os

time.sleep(0.9)

print("welcome to recover mode")

time.sleep(0.3)

def sys(command):
    os.system(command)


# NEVER CHANGE THE POSITION OF THIS ARRAY IT WILL BREAK THE PROGRAM
accepted_file_names = {
    "gwsf/hasOpened.gwsf"
}

# src\gwsf\hasOpened.gwsf



while True:
    print("please enter the name of the file you wish to recover (make sure to put the file extension!) ")
    fileNeedFixing = input(">")
    fileNeedFixing = "gwsf/" + fileNeedFixing
    if fileNeedFixing not in accepted_file_names:
        print("this file is not in the accepted file list\nplease try again")
        time.sleep(0.3)
    else:
        fileOpened = open(fileNeedFixing, "w")
        if fileNeedFixing == "gwsf/hasOpened.gwsf":
            while True:
                print("have you ever used GlassWare Launcher before? (y/n)")
                answer = input(">")
                if answer == "y":
                    fileOpened.write("1")
                    print("FILE RECOVERED\nplease restart GlassWare Launcher")
                    sys("pause")
                    exit(0)
                elif answer == "n":
                    fileOpened.write("0")
                    print("FILE RECOVERED\nplease restart GlassWare Launcher")
                    sys("pause")
                    exit(0)
                else:
                    print("please enter a valid answer")




