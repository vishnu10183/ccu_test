cmd_/home/pi/VishnuM/Aurora-CCU/TestCodes/3_05MAR21/Linux_kernal_basics/Module.symvers := sed 's/ko$$/o/' /home/pi/VishnuM/Aurora-CCU/TestCodes/3_05MAR21/Linux_kernal_basics/modules.order | scripts/mod/modpost -m -a   -o /home/pi/VishnuM/Aurora-CCU/TestCodes/3_05MAR21/Linux_kernal_basics/Module.symvers -e -i Module.symvers   -T -