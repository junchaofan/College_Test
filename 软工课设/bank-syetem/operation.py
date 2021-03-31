import os
import time
import random
import pickle
import getpass
class Person():
	def __init__(self,name,credit_card,iphone,card):
		self.name=name #名字
		self.credit_card=credit_card #身份证号
		self.iphone=iphone #联系方式
		self.card=card
	
class Card():
	def __init__(self,card_id,password,money):
		self.card_id=card_id #卡号
		self.password=password #密码
		self.money=money #余额
		self.loan=0 #贷款
		self.islock=False #判断标志，是否已被挂失

class Bank_Acount():
	def __init__(self,users):
		#字典存储用户信息
		self.users=users
		#用于输出各种卡状态 
		self.phrases={0:"此卡不存在!",1:"此卡已挂失!",2:"密码验证错误,卡已被锁,请先解锁!",3:"客户登陆成功!"}	

##系统登陆
	def sign_in(self):
		pwd = getpass.getpass("请输入高级权限密码:")
		if pwd != 'root':
			print("\n\t\t《《密码错误!》》")
			return 0
		else:
			print("验证通过")
			return 1

##获取系统时间		
	def get_time(self):
		localtime = time.asctime(time.localtime(time.time()))
		print("本地时间:"+str(localtime))
		
##随即获取id值
	def get_id(self):
		while True:
			#调用randint函数生成卡号
			card_id = random.randint(10000000,99999999)
			if card_id not in self.users:
				return card_id
		
##重复验证密码,三次未通过认证失败
	def check_pwd(self,real_pwd):
		for i in range(3):
			input_pwd=getpass.getpass("请验证密码:")
			if input_pwd == real_pwd:
				return True
		return False
	
##检查用户状态
	def check_user(self,card_id):
		#银行卡不存在
		if card_id not in self.users:
			return 0
		#银行卡已被锁
		elif  self.users[card_id].card.islock:
			return 1
		#银行卡存在且未锁,验证密码未通过
		elif not self.check_pwd(self.users[card_id].card.password):
			return 2
		#满足条件
		return 3
	
##初始化
	def ok(self):
		for key in self.users.keys():
			self.users[key].card.loan=int(self.users[key].card.loan) 
	
##处理卡信息
	def work(self):
		for key in self.users.keys():
			#遍历处理所有银行卡的数字信息，使其保留两位有效数字
			self.users[key].card.money=round(self.users[key].card.money,2)
			self.users[key].card.loan=round(self.users[key].card.loan,2)
	
##显示当前卡信息
	def show(self,card_id):
		self.work()
		user=self.users[card_id]
		print("用户名:    "+user.name)
		print("身份证号:  "+user.credit_card)
		print("联系方式:  "+user.iphone)
		print("卡号:      "+str(card_id))
		print("余额:      "+str(user.card.money)+"元")
		print("贷款:      "+str(user.card.loan)+"元")
		if user.card.islock:
			print("状态:      已挂失\n")
		else:
			print("状态:      使用中\n")
			
####开户			
	def creat_user(self):
		judge=False
		#输入根用户密码,升级权限
		if self.sign_in()==1:
			judge=True
		while judge:
			name=input("用户名称:")
			#名字未全字母
			if (name.isalpha()==False):
				print("不合法，请重新输入")
				time.sleep(1)
				break
			credit_card=input("身份证号:")
			#身份证未全数字
			if (credit_card.isdigit()==False):
				print("不合法，请重新输入")
				time.sleep(1)
				break
			for key in self.users.keys():
				#遍历信息栏,若该身份证已办过银行卡,检查是否名字与身份证相符
				if self.users[key].credit_card==credit_card:
					if self.users[key].name!=name:
						print("名字与身份证不相符,请确认后输入")
						break
			iphone=input("联系方式:")
			#联系方式未全数字
			if (iphone.isdigit()==False):
				print("不合法，请重新输入")
				time.sleep(1)
				break
			pre_money=int(input("请输入预存金额:"))
			if (pre_money<0):
				print("预存金额不足,开户失败！")
				break
			money=pre_money
			card_id=self.get_id()
			password=getpass.getpass("请设置密码:")
			while (not self.check_pwd(password)):
				print("密码错误,重新设置")
				password=input("请设置密码:")
			#生成银行卡
			card=Card(card_id,password,money)
			user=Person(name,credit_card,iphone,card)
			self.users[card_id]=user
			print("开户成功")
			self.show(card_id)
			judge=False
		
####销户		
	def delete_user(self):
		judge=False
		#升级权限失败则不能实现root操作
		if self.sign_in()==1:
			judge=True
		#升级权限成功,实现root操作
		while judge:
			card_id=input("请输入卡号:")
			if card_id.isdigit()==False:
				print("输入不合法,请重新输入")
			else:
				card_id=int(card_id)
				cnt=self.check_user(card_id)
				if cnt==3:			
					del self.users[card_id]
					print("销户成功")
				else:
					print(self.phrases[cnt])
				judge=False
		
####存钱
	def deposit_money(self):
		while True:
			card=input("请输入卡号:")
			if card.isdigit()==False:
				print("输入不合法,请重新输入")
			else:
				card_id=int(card)
				cnt=self.check_user(card_id)
				break
		if cnt==3:
			self.show(card_id)
			while True:
				money=input("您需要存入现金金额:")
				if money.isdigit()==False:
					print("输入不合法,请重新输入")
				else:
					money=int(money)
					break
			if money>0:
				self.users[card_id].card.money += money
				self.show(card_id)
		else:
			print(self.phrases[cnt])
		
####取钱	
	def withdraw_money(self):
		#卡号登录
		while True:
			card_id=input("请输入卡号:")
			if card_id.isdigit()==False:
				print("输入不合法,请重新输入")
			else:
				card_id=int(card_id)
				cnt=self.check_user(card_id)
				break
		#cnt返回3表示登录成功,可以进行相应操作
		if cnt==3:
			self.show(card_id)
			while True:
				money=input("您需要取出现金金额:")
				if money.isdigit()==False:
					print("输入不合法,请重新输入")
				else:
					money=int(money)
					break
			if money>0:
				if money<self.users[card_id].card.money:
					self.users[card_id].card.money -= money
					self.show(card_id)
				else:
					print("卡内余额不足,操作失败")
		else:
			print(self.phrases[cnt])
		
####转账		
	def transfer_money(self):
		#卡号登录
		while True:
			card_id1=input("(只接受本行转账)请输入卡号:")
			if card_id1.isdigit()==False:
				print("输入不合法,请重新输入")
			else:
				card_id1=int(card_id1)
				cnt=self.check_user(card_id1)
				break
		#cnt返回3表示登录成功,可以进行相应操作
		if cnt==3:
			self.show(card_id1)
			while True:
				card_id2=input("请输入对方卡号:")
				if card_id2.isdigit()==False:
					print("输入不合法,请重新输入")
				else:
					card_id2=int(card_id2)
					break
			if card_id2 in self.users:
				self.show(card_id2)
				while True:
					money=input("您需要存入现金金额:")
					if money.isdigit()==False:
						print("输入不合法,请重新输入")
					else:
						money=int(money)
						break
				if money<=self.users[card_id1].card.money:
					self.users[card_id1].card.money-=money;
					self.users[card_id2].card.money+=money;
					self.show(card_id1)
					self.show(card_id2)
		else:
			print(self.phrases[cnt])
			
####修改密码		
	def change_pwd(self):
		#卡号登录
		while True:
			card_id=input("请输入卡号:")
			if card_id.isdigit()==False:
				print("输入不合法,请重新输入")
			else:
				card_id=int(card_id)
				break
		change=0
		#cnt返回3表示登录成功,可以进行相应操作
		if card_id in self.users:
			while True:
				credit=input("请输入身份证号:")
				if credit.isdigit()==False:
					print("输入不合法,请重新输入")
				else:
					break
			if credit == self.users[card_id].credit_card:
				new_pwd=getpass.getpass("请输入新密码:")
				self.users[card_id].password=new_pwd
				print("修改成功\n")
				self.show(card_id)
			else:
				print("验证未通过,不能修改密码")
		else:
			print(self.phrases[0])
				
####挂失	
	def report_card(self):
		#升级权限成功,实现root操作;升级权限失败则不能实现root操作
		if self.sign_in()==1:
			while True:
				card_id=input("请输入卡号:")
				if card_id.isdigit()==False:
					print("输入不合法,请重新输入")
				else:
					card_id=int(card_id)
					cnt=self.check_user(card_id)
					break
			#cnt返回3表示登录成功,可以进行相应操作
			if cnt==3:
				self.users[card_id].card.islock=True
				print("已挂失")
			else:
				print(self.phrases[cnt])
		
####解挂失	
	def hang_out(self):
		#root成功,可以进行相应操作
		if self.sign_in()==1:
			while True:
				card_id=input("请输入卡号:")
				if card_id.isdigit()==False:
					print("输入不合法,请重新输入")
				else:
					card_id=int(card_id)
					break
			if card_id in self.users:
				password=getpass.getpass("请输入密码:")
				if self.check_pwd(password):
					if self.users[card_id].card.islock:
						self.users[card_id].card.islock=False
						print("该银行卡已解挂失")
					else:
						print("该银行卡未挂失")
				else:
					print("密码错误")

####查询
	def show_card(self):
		#卡号登录
		while True:
			card_id=input("请输入卡号:")
			if card_id.isdigit()==False:
				print("输入不合法,请重新输入")
			else:
				card_id=int(card_id)
				cnt=self.check_user(card_id)
				break
		#cnt返回3表示登录成功,可以进行相应操作
		if cnt==3:
			self.show(card_id)
		if cnt==3 and self.users[card_id].card.loan!=0:
			judge=input("是否偿还贷款?[y]\t[n]\n请输入:")
			if judge=='y' or judge=='Y':
				count1=self.users[card_id].card.money
				print("您当前银行存款是:"+str(count1)+"元")
				count2=self.users[card_id].card.loan
				print("您当前需要偿还贷款是:"+str(count2)+"元")
				if count2 <= count1:
					print("贷款已还清,剩余额度将转存入本卡")
					self.users[card_id].card.loan=0
					self.users[card_id].card.money=round(count1-count2,2)
				else:
					print("扣除卡内余额,您尚需偿还"+str(round(count2-count1,2))+"元")
					count3=input("请输入偿还金额:")
					while True:
						if count3.isdigit()==False:
							print("输入不合法,请重新输入")
						else:
							count3=int(count3)
							break
					if count3>count2-count1:
						print("贷款已还清,剩余额度将转存入本卡")
						self.users[card_id].card.loan=0
						self.users[card_id].card.money=round(count3+count1-count2,2)
					else:
						print("扣除卡内余额,您尚需偿还"+str(round(count2-count1-count3,2))+"元")
						self.users[card_id].card.loan=round(count2-count1-count3,2)
						self.users[card_id].card.money=0
			self.show(card_id)
		else:
			print(self.phrases[cnt])
		
		
####外汇	
	def foreign_currency(self):
		judge=True
		choice=input("[1]存外汇   [2]取外汇\n请选择:")
		if choice!='1' and choice!='2':
			print("输入不合法")			
			judge=False
		while judge:
			print("当前可操作外汇汇率")
			print("[1]欧元   1欧元=7.9076人民币")
			print("[2]美元   1美元=6.931人民币")
			print("[3]日元   1日元=0.06096人民币")
			count=input("请选择外汇类型:")
			if count=='1':
				num=7.9076
				break
			elif count=='2':
				num=6.931
				break
			elif count=='3':
				num=0.06096
				break
			else:
				print("请重新选择:")
		while judge:
			while True:
				#卡号登录
				card_id=input("请输入卡号:")
				if card_id.isdigit()==False:
					print("输入不合法,请重新输入")
				else:
					card_id=int(card_id)
					cnt=self.check_user(card_id)
					break
			if cnt!=3:
				print(self.phrases[cnt])
				break
			user=self.users[card_id]
			self.show(card_id)
			if choice=='1':
				while True:
					money=input("存入外汇金额:")
					if money.isdigit()==False:
						print("输入不合法,请重新输入")
					else:
						money=int(money)
						break
				user.card.money+=money / num
				self.show(card_id)
			else:
				while True:
					money=input("所取外汇金额:")
					if money.isdigit()==False:
						print("输入不合法,请重新输入")
					elif int(money)>user.card.money:
						print("余额不足,本卡余额:"+int(user.card.money)+"元,请重新输入")
					else:
						money=int(money)
						break
				user.card.money-=money * num
				self.show(card_id)
			judge=False
		
####贷款		
	def credit_money(self):
		#卡号登录
		while True:
			card_id=input("请输入卡号:")
			if card_id.isdigit()==False:
				print("输入不合法,请重新输入")
			else:
				card_id=int(card_id)
				cnt=self.check_user(int(card_id))
				break
		if cnt==3:
			if self.users[card_id].card.loan==0:
				while True:
					loan=input("请输入贷款额度:")
					if loan.isdigit()==False:
						print("输入不合法,请重新输入")
					else:
						loan=int(loan)
						break
				self.users[card_id].card.loan=loan
				self.show(card_id)
			else:
				print("您的上次贷款共计"+str(self.users[card_id].card.loan)+"元尚未归还,不能二次贷款")
		else:
			print(self.phrases[cnt])
			
####个人
	def look_card(self):
		#升级权限失败则不能实现root操作#升级权限成功,实现root操作
		if self.sign_in()==1:
			cards={}
			count=0
			while True:
				credit=input("请输入身份证号:")
				if credit.isdigit()==False:
					print("输入不合法,请重新输入")
				else:
					break
			for key in self.users.keys():
				if  self.users[key].credit_card==credit:
					cards[key]=self.users[key].card
			for key in cards.keys():
				count+=1
				print("第"+str(count)+"张卡")
				print("卡号:     "+str(cards[key].card_id))
				print("余额:     "+str(cards[key].money)+"元")
				print("贷款:     "+str(cards[key].loan)+"元")
			if count==0:
				print("该身份证尚未开户!")
			
####资料
	def traversal(self):
		#升级权限失败则不能实现root操作#升级权限成功,实现root操作
		if self.sign_in()==1:
			if len(self.users)==0:
				print("资料库为空")
			else:
				count=0		
			for key in self.users.keys():
				count+=1
				print("第"+str(count)+"张卡")
				print("$$$$$$$$$$$$$$$$$$$$$$$$$")
				self.show(key)
				print("密码:      "+self.users[key].card.password)
				print("$$$$$$$$$$$$$$$$$$$$$$$$$\n\n")
####退出	
	def exit(self):
		#打开文件并保存
		with open("user.txt","wb") as file_object:
			pickle.dump(self.users,file_object)
