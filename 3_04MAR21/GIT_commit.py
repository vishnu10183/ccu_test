from datetime import datetime
import subprocess

def git_commit():
        print("Adding files to Local GIT repository...", end= ' ')
        tmp=subprocess.call( ["git", "add", "."], cwd="/home/pi/VishnuM/Aurora-CCU/TestCodes")
        if not tmp:
                print("DONE")
        else:
                print("ERROR")

                
        now = datetime.now()
        comment = 'Updated ' + now.strftime( "%d-%b" )
        
        print("Committing files...", end= ' ')
        tmp=subprocess.call( ["git", "commit", "-m", comment ], cwd="/home/pi/VishnuM/Aurora-CCU/TestCodes")
        if not tmp:
                print("DONE")
        else:
                print("ERROR")

                
        print("Pushing the files to RPi4 branch....", end= ' ')
        tmp=subprocess.call( ["git", "push", "-u", "origin", "RPi4", "--force"], cwd="/home/pi/VishnuM/Aurora-CCU/TestCodes")
        if not tmp:
                print("DONE")
        else:
                print("ERROR")


if __name__ == '__main__':
    git_commit()
