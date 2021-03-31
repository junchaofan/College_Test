from admin import Admin
import pickle
from operation import Bank_Acount

def main():
	#初始化对象
	ad_owner=Admin("666","999")
	if ad_owner.login()==-1:
		return -1
	ad_owner.welcome()
	#加载用户信息文件
	with open("user.txt","rb") as file_object:
		users=pickle.load(file_object)
	atm=Bank_Acount(users)
	atm.ok()
	while True:
		ad_owner.admin_interface()
		atm.get_time()
		choice=input("请选择操作项:")
		if choice=='0':
			#开户
			atm.creat_user()
		elif choice=='1':
			#销户
			atm.delete_user()
		elif choice=='2':
			#存钱
			atm.deposit_money()
		elif choice=='3':
			#取钱
			atm.withdraw_money()
		elif choice=='4':
			#转账
			atm.transfer_money()
		elif choice=='5':
			#改密码
			atm.change_pwd()
		elif choice=='6':
			#挂失
			atm.report_card()
		elif choice=='7':
			#解挂失
			atm.hang_out()
		elif choice=='8':
			#查询
			atm.show_card()
		elif choice=='9':
			#外汇
			atm.foreign_currency()
		elif choice=='s':
			#贷款
			atm.credit_money()
		elif choice=='c':
			#个人资料
			atm.look_card()
		elif choice=='r':
			#管理员浏览全部资料
			atm.traversal()
		elif choice=='q':
			#退出
			atm.exit()
			return	

if __name__ == "__main__":
	main()
