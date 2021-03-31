import os
import time
import pickle
class Person():
	def __init__(self,name,credit_card,iphone):
		self.name=name #名字
		self.credit_card=credit_card #身份证号
		self.iphone=iphone #联系方式
		self.card=card
	
class Card():
	def __init__(self,userid,password,money,islock):
		self.card_id=card_id #卡号
		self.password=password #密码
		self.money=money #余额
		self.islock=False #判断标志，是否已被挂失

class Bank_Acount():
	def __init__(self,users):
		self.users=users #字典
		self.phrases={0:"此卡不存在!",1:"此卡已挂失!",2:"密码验证错误,卡已被锁,请先解锁!",3:"客户登陆成功!"}
		
	def get_time(self):
		loacltime = time.asctime(time.localtime(time.time()))
		print("本地时间:"+str(localtime))
		
	def get_id(self):
		while True:
			card_id = random.randint(10000000,99999999)
			if card_id not in self.users:
				return card_id
		
	def check_pwd(self,real_pwd):
		for i in range(3):
			input_pwd=input("请验证密码:")
			if input_pwd == real_pwd:
				return True
		return False
	
	def check_user(self,card_id):
		user=self.users.get(card_id)
		if not user:
			del self.users[card_id]
			return 0
		if not user.card.islock:
			return 1
		if not self.check_pwd(user.card.password):
			return 2
		return 3
	
	def show(self,card_id):
		user=self.users[card_id]
		print("用户名:    "+user.name)
		print("身份证号:  "+user.credit_card)
		print("联系方式:  "+user.iphone)
		print("卡号:     "+card_id)
		print("余额:     "+user.card.money)
		if user.card.islock:
			print("状态:     使用中\n")
		else:
			print("状态:     已挂失\n")
			
####开户			
	def creat_user(self):
		judge=True
		while judge:
			name=input("用户名称:")
			if (name.isalpha()==False):
				print("不合法，请重新输入")
				time.sleep(1)
				break
			credit_card=input("身份证号:")
			if (credit_card.isdigit()==False):
				print("不合法，请重新输入")
				time.sleep(1)
				break
			iphone=input("联系方式")
			if (iphone.isdigit()==False):
				print("不合法，请重新输入")
				time.sleep(1)
				break
			pre_money=int(input("请输入预存金额:"))
			if (pre_money<0):
				print("预存金额不足,开户失败！")
				break
			money=pre_money
			card_id=get_id()
			password=input("请设置密码:")
			while (!check_pwd(password)):
				print("密码错误,重新设置")
				password=input("请设置密码:")
			card=Card(card_id,password,money)
			user=Person(name,credit_card,iphone,card)
			self.users[card_id]=user
			print("开户成功")
			self.show(card_id)
			judge=False
		
####销户		
	def delete_user(self):
		card_id=int(input("请输入卡号:"))
		cnt=self.check_user(card_id)
		if cnt==3:			
			del self.users[card_id]
			print("销户成功")
		else:
			print(self.phrases[cnt])	
		
####存钱
	def deposit_money(self):
		card_id=int(input("请输入卡号:"))
		cnt=self.check_user(card_id)
		if cnt==3:
			self.show(card_id)
			money=int(input("您需要存入现金金额:"))
			if money>0:
				self.users[card_id].card.money += money
				self.show(card_id)
		else:
			print(self.phrases[cnt])
		
####取钱	
	def withdraw_money(self):
		card_id=int(input("请输入卡号:"))
		cnt=self.check_user(card_id)
		if cnt==3:
			self.show(card_id)
			count=int(input("您需要取出现金金额:"))
			if count>0:
				if count<self.users[card_id].card.money:
					self.users[card_id].card.money -= count
					self.show(card_id)
		else:
			print(self.phrases[cnt])
		
####转账		
	def transfer_money(self):
		card_id1=int(input("(只接受本行转账)请输入卡号:"))
		cnt=self.check_user(card_id1)
		if cnt==3:
			self.show(card_id1)
			card_id2=int(input("请输入对方卡号:"))
			if card_id2 in self.users:
				self.show(card_id2)
				count=int(input("请输入转账金额:"))
				if count<=self.users[card_id1].card.money:
					self.users[card_id1].card.money-=count;
					self.users[card_id2].card.money+=count;
					self.show(card_id1)
					self.show(card_id2)
		else:
			print(self.phrases[cnt])
			
####修改密码		
	def change_pwd(self):
		card_id=int(input("请输入卡号:"))
		cnt=self.check_user(card_id)
		change=0
		if cnt==3:
			for i in range(3):
				credit=input("请输入身份证号:")
				if credit == self.users[card_id].credit_card:
					new_pwd=input("请输入新密码:")
					self.users[card_id].credit_card=new_pwd
					change=1
					break 
			if change:
				print("修改成功\n")
				self.show(card_id)
		else:
			print(self.phrases[cnt])
				
####挂失	
	def report_card(self):
		card_id=int(input("请输入卡号:"))
		cnt=self.check_user(card_id)
		if cnt==3:
			self.users[card_id].card.islock=False
		else
			print(self.phrases[cnt])
		
####解挂失	
	def hang_out(self):
		card_id=int(input("请输入卡号:"))
		cnt=self.check_user(card_id)
		if cnt==3:
			self.users[card_id].card.islock=True
		else
			print(self.phrases[cnt])
		
####补办卡	
	def reissue_card(self):
		card_id=int(input("请输入卡号:")) 
		
		
		
		
		
		
		cnt=self.check_user(card_id)
		if cnt==3:
			credit=input("请输入身份证号:")
			for key in self.users.keys():
				if  self.users[key].credit_card==credit:
					pre_money=int(input("请输入原存折金额:"))
					if (pre_money>=0):
						money=pre_money
						card_id=get_id()
						password=input("请设置密码:")
						while (!check_pwd(password)):
							print("密码错误,重新设置")
							password=input("请设置密码:")
						card=Card(card_id,password,money)
						self.users[key].Card=card
					print("补办成功")
					self.show(card_id)
					else:	
						print("预存金额不足,开户失败！")  
		else
			print(self.phrases[cnt])
		
		
####外汇	
	def foreign_currency(self):
		
		
####贷款		
	def credit_money(self):
		
		
	
	def exit(): 
				
