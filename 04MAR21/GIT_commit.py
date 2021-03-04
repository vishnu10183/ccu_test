from datetime import datetime
import subprocess

work_dir = "D:\\VishnuM\\Aurora\\1_CCU_RPi\\CCU_testCodes"

def git_commit():
        print("Adding files to Local GIT repository...", end= ' ')
        tmp=subprocess.call( ["git", "add", "."], cwd= work_dir )
        if not tmp:
                print("DONE")
        else:
                print("ERROR")

                
        now = datetime.now()
        comment = 'Updated ' + now.strftime( "%d-%b" )
        
        print("Committing files...", end= ' ')
        tmp=subprocess.call( ["git", "commit", "-m", comment ], cwd= work_dir)
        if not tmp:
                print("DONE")
        else:
                print("ERROR")

                
        print("Pushing the files to PC branch....", end= ' ')
        tmp=subprocess.call( ["git", "push", "-u", "origin", "PC", "--force"], cwd= work_dir)
        if not tmp:
                print("DONE")
        else:
                print("ERROR")


if __name__ == '__main__':
    git_commit()