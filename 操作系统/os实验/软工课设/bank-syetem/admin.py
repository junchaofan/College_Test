from time import sleep
class Admin():
	def __init__(self,admin_id,password):
		self.admin_id='666'
		self.password='999'
		
	def login(self):
		acount = input("请输入管理员账户:")
		if acount != self.admin_id:
			print("\t\t《《《账号错误！》》")
			return -1
		else:
			pwd = input("请输入管理员密码:")
			if pwd != self.password:
				print("\t\t《《密码错误!》》")
				return -1
			else:
				print("登陆成功，即将进入管理员界面...")
				time.sleep(2)
				return 0
	
	def welcome(self):
		print("\n\n\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$")
		print("\t$                                       $")
		print("\t$                                       $")
		print("\t$                                       $")
		print("\t$           欢迎登陆银行管理系统            $")
		print("\t$                                       $")
		print("\t$    制作人：樊俊超       语言：python      $")
		print("\t$                                       $")
		print("\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$")
		time.sleep(2)
		
	def admin_interface(self):
		print("\n\n\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$")
		print("\t$                                       $")
		print("\t$     【0】开户                【1】销户   $")
		print("\t$     【2】存款                【3】取款   $")
		print("\t$     【4】转账                【5】密改   $")
		print("\t$     【6】挂失                【7】解挂   $")
		print("\t$     【8】补卡                【9】外汇   $")
		print("\t$     【s】贷款                【q】退出   $")
		print("\t$                                       $")
		print("\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$")
