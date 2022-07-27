from bs4 import BeautifulSoup as bs4
import requests
import webbrowser

need_an_update = False;

# open https://thunderous-marzipan-35cf95.netlify.app/ and get a value from an id of "upDateCheckNumber" and put it in a variable
def checkForUpdates():
    url = "https://thunderous-marzipan-35cf95.netlify.app/"
    r = requests.get(url)
    soup = bs4(r.text, 'html.parser')
    updateCheckNumber = soup.find(id="upDateCheckNumber").get_text()
    return updateCheckNumber

def checkVersion():
    url = "https://thunderous-marzipan-35cf95.netlify.app/"
    r = requests.get(url)
    soup = bs4(r.text, 'html.parser')
    version = soup.find(id="versionCheckNumber").get_text()
    return version

internal_version = open("./gwsf/version.gwsf", "r")
internal_version = internal_version.read()



master_version = checkVersion()


if checkForUpdates() == "1":
    need_an_update = True
else:
    need_an_update = False

if need_an_update:
    if master_version != internal_version:
        internal_version_write = open("./gwsf/version.gwsf", "w")
        print("There is an update available!")
        print("The current version is: " + internal_version)
        print("The latest version is: " + master_version)
        print("Please wait...")
        internal_version_write.write(master_version)
        internal_version_write.close()
        webbrowser.open("https://thunderous-marzipan-35cf95.netlify.app/update.file/windows_version6.4.zip")
    else:
        print("You are up to date!")
else:
    print("You don't need to update the program!")