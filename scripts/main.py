






from tools import tools
from tools import proxy
from termcolor import colored
import requests                     




# Why are you reading this?
# Better subscribe to Telegram - https://t.me/








# There are 1500+ lines in this project,
# if you count user_agent.py and services.json,
# then there will be 2267 lines,
# Wow, right?








tools.clear()
tools.ICC()
tools.clear()
tools.check_files()
tools.CFU()
tools.CTF()








while True:
	tools.clear()
	tools.banner()
	tools.banner_tools()








	try:
		tool = input(colored("\n~# ", "red"))
	except KeyboardInterrupt:
		continue
	if tool == "1":
		numb, ct, pr = tools.start_input()
		if numb != 0:
			tools.start(numb, ct, proxy_=pr)
	elif tool == "0":
		tools.clear()
		break
	elif tool == "99":
		tools.banner_info()
	elif tool == "2":
		tools.donate()
	#elif tool == "3":
		#tools.inst_logs()
	elif tool.lower() == "3":
		tools.app()
	elif tool.lower() == "clear logs":
		tools.clear_logs()
	elif tool.lower() == "update":
		tools.force_update()
	else:
		pass
