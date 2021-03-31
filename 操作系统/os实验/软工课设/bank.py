# ATM

##具体功能有:

?	1.开户
?	2.查询
?	3.存钱
?	4.取钱
?	5.转账
?	6.改密
?	7.锁卡
?	8.解锁
?	9.补卡
?	10.销户
?	11.外汇存入
?	12.保存退出
?	管理员账号为admin 密码: 123

?	先创建一个user.txt存放用户信息

?	将所有文件放到bank文件夹下

```python
?```
### 创建一个叫main的.py文件
"""
类名:Person
属性:姓名、身份证号、手机号、卡

类名:card
属性:卡号、密码、余额

类名:View
属性:无

类名:ATM机功能
"""

from bank.view import View
from bank.operation import Operation
# 先实例化显示界面的类
v = View()

# 主函数
def main():
    # 调用显示界面的类中的管理员登录方法
    v.login()
    # 调用功能的类中的初始化方法(打印每个账户信息, 方便查看)
    o = Operation()
    while View.a:
        choice = input("请选择需要的服务项目:")
        # 选择项目1, 调用功能类中的注册方法及保存方法
        if choice == "1":
            o.register()
            o.exit()
        # 选择项目2, 调用功能类中的查询方法及保存方法
        elif choice == "2":
            o.query()
            o.exit()
        # 选择项目3, 调用功能类中的存钱方法及保存方法
        elif choice == "3":
            o.save_money()
        # 选择项目4, 调用功能类中的取钱方法及保存方法
        elif choice == "4":
            o.draw_money()
            o.exit()
        # 选择项目5, 调用功能类中的转账方法及保存方法
        elif choice == "5":
            o.trans_money()
            o.exit()
        # 选择项目6, 调用功能类中的改密方法及保存方法
        elif choice == "6":
            o.change_password()
            o.exit()
        # 选择项目7, 调用功能类中的锁卡方法及保存方法
        elif choice == "7":
            o.lock()
            o.exit()
        # 选择项目8, 调用功能类中的解锁方法及保存方法
        elif choice == "8":
            o.unlock()
            o.exit()
        # 选择项目9, 调用功能类中的补卡方法及保存方法
        elif choice == "9":
            o.replace()
            o.exit()
        # 选择项目10, 调用功能类中的销户方法及保存方法
        elif choice == "10":
            o.remove()
            o.exit()
        # 选择项目11, 调用功能类中的外汇存入方法及保存方法
        elif choice == "11":
            o.Save_monet()
            o.exit()
        # 选择项目0, 调用功能类中保存方法并跳出循环
        elif choice == "0":
            o.exit()
            break
        # 输入的项目序号有误
        else:
            print("输入有误，请重新选择！")


if __name__ == '__main__':
    main()
?```
```

```python
?```
＃### 创建一个叫view.py的文件
＃创建一个显示界面的类

＃类里面有登录管理员账号的方法及显示功能的方法




from time import sleep
class View:

    a = 0



    def login（self）：

        name = input（“请输入管理员账号：”）

        pwd = input（“请输入管理员密码：”）

        如果name ==“admin”和pwd ==“123”：

            self.login_view（）

            sleep（0.5）

            self.opration_view（）

            View.a = 1

        其他：

            打印（ “账号或密码不正确”）



    def login_view（self）：

        打印（”************************************”）

        打印（“*                                  *”）

        打印（“*                                  *”）

        打印（“*                   ATM            *”）

        打印（“*                                  *”）

        打印（“*                                  *”）

        打印（”************************************”）



    def opration_view（self）：

        打印（”************************************”）

        print（“*          1.开户      2.查询      *”）

        print（“*          3.存钱      4.取钱      *”）

        print（“*          5.转账      6.改密      *”）

        print（“*          7.锁卡      8.解锁      *”）

        print（“*          9.补卡      10.销户     *")
        print（“*         11.外汇存入（需要验证）    *”）

        print（“*         12.保存退出              *”）
 ```
```

```python
?```
### 创建一个叫person.py的文件
# 创建人的类
# 人的属性有用户名, 身份证号码, 手机号, 卡
class Person:
    def __init__(self, name, userid, phone, card):
        self.name = name
        self.userid = userid
        self.phone = phone
        self.card = card
 ```
```

```python
?```
### 创建一个叫card.py的文件
# 创建卡的类
# 卡的属性有 卡号, 密码, 余额, 是否被锁卡的判定
class Card:
    def __init__(self, cardid, password, money):
        self.cardid = cardid
        self.password = password
        self.money = money
        self.islock = False
 ```
```

```python
?```
### 创建一个叫operation.py的文件
""""""
import pickle
import os
import random
from bank.card import Card
from bank.person import Person

"""
当我们第一次打开系统的时候   字典为空
再次打开系统时   自动加载已有的用户
"""


# 创建一个功能类
class Operation:
    # 初始化方法, 打印所有的用户信息
    def __init__(self):
        try:
            self.load_user()
            print(self.user_dict)
        except BaseException:
            print('执行错误, 请先删除user.txt文件')
            exit()

    # 加载用户信息
    def load_user(self):
        # 判断文件是否存在
        if os.path.exists("user.txt"):
            with open("user.txt", "rb") as f:
                self.user_dict = pickle.load(f)
        # 不存在则创建一个空字典
        else:
            self.user_dict = {}

    # 注册
    def register(self):
        while True:
            # 输入姓名
            name = input("请输入您的姓名:")
            # 如果用户名是由数字字母汉字组成
            if name.isalnum():
                # 跳出循环
                break
            else:
                print('姓名格式不对')
        # 输入身份证号
        a = True
        while a:
            userid = input("请输入您的身份证号:")
            # 如果身份证号码是由十进制数字组成
            if userid.isdigit():
                # 如果用户信息的文件存在
                if os.path.exists('user.txt'):
                    # 遍历所有的卡号
                    for var in range(100000, 1000000):
                        # 通过卡号得到值
                        p = self.user_dict.get(var, 10)
                        if p == 10:
                            pass
                        else:
                            # 如果创建的身份证号码已经存在
                            if p.userid == userid:
                                print('身份证号码重复')
                                break
                            else:
                                pass
                        if var == 999999:
                            a = False
                else:
                    break
            else:
                print('身份证号格式不对')
        # 输入手机号
        while True:
            phone = input("请输入您的手机号:")
            # 如果手机号是由十进制数字组成
            if phone.isdigit():
                break
            else:
                print('手机号格式不对')
        # 输入密码  确认密码
        password = self.get_pwd()
        # 生成卡号
        cardid = self.get_cardid()
        # 获取一张卡
        card = Card(cardid, password, 10)
        # 通过卡找到用户
        user = Person(name, userid, phone, card)
        # 保存用户信息
        self.user_dict[cardid] = user
        print("恭喜%s开卡成功,您的卡号为:%s,开内余额%s元" % (name, cardid, card.money))

    # 设置密码
    def get_pwd(self):
        while True:
            pwd1 = input("请输入您的密码:")
            # 如果密码是由数字字母汉字组成
            if pwd1.isalnum():
                # 再次输入密码
                pwd2 = input("请确认您的密码:")
                # 如果两次输入相同
                if pwd1 == pwd2:
                    # 返回密码
                    return pwd1
                else:
                    print("两次密码不一致，请重新输入")
            else:
                print('密码格式不对')

    # 生成随机卡号
    def get_cardid(self):
        while True:
            # 随机数生成卡号
            cardid = random.randint(100000, 999999)
            # 如果卡号不存在
            if cardid not in self.user_dict:
                return cardid

    # 查询
    def query(self):
        # 拿到一张卡
        card = self.get_card_info()
        if not card:
            print("卡不存在!")
        # 判断卡是否被锁定
        else:
            if card.islock:
                print("卡被锁定了!")
            else:
                # 检测卡的密码
                lock = self.check_pwd(card)
                if lock:
                    print("卡内余额%s元!" % card.money)

    # 检测密码
    def check_pwd(self, card):
        # 记录卡密输错几次的参数
        count = 1
        while count < 4:
            pwd = input("请输入您的密码:")
            # 判断用户输入的密码是否和卡内的密码一致
            if pwd == card.password:
                return True
            else:
                # 不一致则参数+1
                count += 1
                if count == 4:
                    # 锁卡
                    card.islock = True
                    print("密码输入三次失败，卡已经被锁定!")

    # 获取卡信息
    def get_card_info(self):
        # 用户输入卡号
        cardid = input("请输入您的卡号:")
        # 如果卡号是由十进制数字组成
        if cardid.isdigit():
            cardid = int(cardid)
            if 100000 <= cardid <= 999999:
                # 判断卡号是否存在
                if cardid not in self.user_dict:
                    return False
                else:
                    # 通过卡号找到用户  存储方式是:user_dict[cardid] = user
                    user = self.user_dict[cardid]
                    # 通过用户找到卡
                    card = user.card
                    return card

    # 存钱
    def save_money(self):
        # 拿到一张卡
        card = self.get_card_info()
        if not card:
            print("卡不存在!")
        else:
            # 判断是否锁定
            if not card.islock:
                # 输入存款金额
                money = input("请输入存款金额:")
                # 如果金额是由十进制数字组成
                if money.isdigit():
                    # 钱 <= 0
                    if int(money) <= 0:
                        print("输入的金额不正确!")
                    else:
                        # 让卡内余额增加money
                        card.money += int(money)
                        print("存款成功,卡内余额为%s元" % card.money)
                else:
                    print('格式不对')
            else:
                print("卡已经被锁定，请先解卡!")

    # 取钱
    def draw_money(self):
        # 拿到一张卡
        card = self.get_card_info()
        if not card:
            print("卡不存在!")
        else:
            # 判断是否锁定
            if not card.islock:
                pwd = input('请输入密码: ')
                # 密码相同
                if pwd == card.password:
                    # 输入取款金额
                    money = input("请输入取款金额:")
                    # 如果金额是由十进制数字组成
                    if money.isdigit():
                        # 如果不满足条件
                        if int(money) <= 0 or int(money) > card.money:
                            print("输入的金额不正确!")
                        else:
                            # 让卡内余额减少money
                            card.money -= int(money)
                            print("取款成功,卡内余额为%s元" % card.money)
                    else:
                        print('格式不对')
                else:
                    print('输入密码错误!')
            else:
                print("卡已经被锁定，请先解卡!")

    # 改密码
    def change_password(self):
        # 获取卡
        card = self.get_card_info()
        if not card:
            print("卡不存在!")
        else:
            # 判断是否被锁定
            if card.islock:
                print("卡已被锁定,请先解锁！")
            else:
                # 调用检测密码的方法
                self.check_pwd(card)
                # 判断是否被锁定
                if card.islock:
                    print("卡已被锁定,请先解锁！")
                else:
                    while True:
                        # 输入新密码
                        pwd3 = input("请输入您的新密码:")
                        # 判断密码是否由数字汉字字母组成
                        if pwd3.isalnum():
                            pwd4 = input("请确认您的新密码:")
                            # 两次输入相同
                            if pwd3 == pwd4:
                                # 判断新密码是否和原密码相同
                                if pwd3 != card.password:
                                    # 密码更新
                                    card.password = pwd3
                                    print('密码设置成功!')
                                    break
                                else:
                                    print('输入的密码与原密码相同, 请重新设置')
                            else:
                                print("两次密码不一致，请重新输入")
                        else:
                            print('密码格式有误')

    # 锁卡
    def lock(self):
        # 获取卡
        card = self.get_card_info()
        if not card:
            print('卡不存在')
        else:
            # 判断是否锁定
            if card.islock == False:
                # 调用检测密码方法
                if self.check_pwd(card):
                    card.islock = True
                    print('锁卡成功')
            else:
                print('卡已经被锁定!')

    # 转账
    def trans_money(self):
        # 先拿到一张卡
        card = self.get_card_info()
        if not card:
            print("卡不存在!")
        else:
            # 判断卡是否被锁
            if card.islock:
                print("卡已被锁定,请先解锁！")
            else:
                # 调用检测密码的方法
                if self.check_pwd(card):
                    # 获取收款方卡号
                    otherid = int(input("请输入对方账号:"))
                    # 判断对方卡号是否存在
                    if otherid not in self.user_dict or otherid == card.cardid:
                        print("错误!!！")
                    else:
                        # 判断是否被锁
                        if card.islock:
                            print("卡已被锁定,请先解锁！")
                        else:
                            # 查出转账用户
                            user = self.user_dict[card.cardid]
                            # 查出被转账用户
                            other_user = self.user_dict[otherid]
                            # 查出被转账用户的卡号
                            other_card = other_user.card
                            # 输入转账金额
                            money = input("请输入转账金额:")
                            # 金额符合条件
                            if money.isdigit():
                                money = int(money)
                                if money > 0 and  money <= card.money:
                                    # 双方的余额更新
                                    card.money -= money
                                    other_card.money += money
                                    print("%s向%s成功转账%s元。" % (
                                        user.name, other_user.name, money
                                    ))
                                else:
                                    print("转账金额有误!")
                            else:
                                print('格式不对')

    # 解锁
    def unlock(self):
        # 拿到一张卡
        card = self.get_card_info()
        if not card:
            print("卡不存在!")
        else:
            # 查出用户
            user = self.user_dict[card.cardid]
            # 判断是否已经被锁定
            if card.islock == False:
                print('卡已被解锁, 无需再次解锁')
            else:
                while True:
                    # 输入密码
                    pwd = input("请输入密码:")
                    # 密码是否相同
                    if pwd == card.password:
                        # 解锁
                        card.islock = False
                        print("恭喜您解锁成功!")
                        break
                    else:
                        # 密码不相同则输入身份证号码
                        userid = input("请输入您的身份证号:")
                        # 判断身份证号码是否一致
                        if userid == user.userid:
                            # 重新设置密码
                            pwd1 = self.get_pwd()
                            card.password = pwd1
                        else:
                            print("身份证号有误！")
                            break

    # 补卡
    def replace(self):
        # 输入身份证号码
        Userid = input('请输入你的身份证: ')
        # 身份证号码符合条件
        if Userid.isdigit():
            # 遍历所有卡号
            for var in range(100000, 1000000):
                # 返回值
                p = self.user_dict.get(var, 10)
                if p == 10:
                     pass
                else:
                    # 判断身份证号码是否相同
                    if p.userid == Userid:
                        # print(var)
                        # 查询出用户
                        user = self.user_dict[var]
                        # 重新生成卡号
                        cardid = self.get_cardid()
                        # 卡号更新
                        user.card.cardid = cardid
                        # 将原卡号对应的用户信息赋值到新卡号对应的用户信息
                        self.user_dict[cardid] = self.user_dict[var]
                        # 删除原用户
                        self.user_dict.pop(var)
                        print('补卡成功, 你的新卡号是%s' % cardid)
                        print(self.user_dict)
                        break
                if var == 999999:
                    print('身份证输入有误')
        else:
            print('身份证号格式不正确')

    # 销户
    def remove(self):
        # 得到卡
        card = self.get_card_info()
        # 调用检测密码方法
        lock = self.check_pwd(card)
        # 判断密码是否输入正确
        if lock:
            # 删除卡号及用户信息
            self.user_dict.pop(card.cardid)
            print('销户成功')
            print(self.user_dict)
        else:
            print('输入密码不正确')

    # 外汇存入
    def Save_monet(self):
        # 打印可以选择的序号
        print('1. 美元    1美元可以存入6.8人民币')
        print('2. 欧元    1欧元可以存入7.9人民币')
        choice = input('请输入序号: ')
        # 选择序号1
        if choice == '1':
            # 得到卡
            card = self.get_card_info()
            if not card:
                print("卡不存在!")
            else:
                # 判断是否锁定
                if not card.islock:
                    # 输入存款金额
                    money = input("请输入存款金额:")
                    # 金额是否符合规则
                    if money.isdigit():
                        money = int(money)
                        if money <= 0:
                            print("输入的金额不正确!")
                        else:
                            a = True
                            while a:
                                # 创建验证码
                                yzm = random.choice('abcdefghijklmnopqrstuvwxyz0123456789') + random.choice('abcdefghijklmnopqrstuvwxyz0123456789') + random.choice('abcdefghijklmnopqrstuvwxyz0123456789') + random.choice('abcdefghijklmnopqrstuvwxyz')
                                print('验证码是', yzm)
                                # 输入验证码
                                num1 = input('请输入验证码: ')
                                # 验证码相同
                                if yzm == num1:
                                    # 让卡内余额增加money
                                    card.money += (money * 6.8)
                                    print("存款成功,卡内余额为%s元" % card.money)
                                    a = False
                                else:
                                    print('验证码错误')
                    else:
                        print('格式不对')
                else:
                    print("卡已经被锁定，请先解卡!")
        # 序号2
        elif choice == '2':
            # 获得卡
            card = self.get_card_info()
            if not card:
                print("卡不存在!")
            else:
                # 判断是否锁定
                if not card.islock:
                    # 输入存款金额
                    money = input("请输入存款金额:")
                    # 判断金额是否符合规则
                    if money.isdigit():
                        money = int(money)
                        if money <= 0:
                            print("输入的金额不正确!")
                        else:
                            a = True
                            while a:
                                # 验证码生成
                                yzm = random.choice('abcdefghijklmnopqrstuvwxyz0123456789') + random.choice('abcdefghijklmnopqrstuvwxyz0123456789') + random.choice('abcdefghijklmnopqrstuvwxyz0123456789') + random.choice('abcdefghijklmnopqrstuvwxyz')
                                print('验证码是', yzm)
                                # 验证码相同
                                num1 = input('请输入验证码: ')
                                if yzm == num1:
                                    # 让卡内余额增加money
                                    card.money += (money * 7.9)
                                    print("存款成功,卡内余额为%s元" % card.money)
                                    a = False
                                else:
                                    print('验证码错误')
                    else:
                        print('格式不对')
                else:
                    print("卡已经被锁定，请先解卡!")
        else:
            print('错误')

    # 保存
    def exit(self):
        # 重新写入保存用户信息的文件
        with open("user.txt", "wb") as f:
            pickle.dump(self.user_dict, f)
?```
```