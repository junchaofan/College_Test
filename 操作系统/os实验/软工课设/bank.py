# ATM

##���幦����:

?	1.����
?	2.��ѯ
?	3.��Ǯ
?	4.ȡǮ
?	5.ת��
?	6.����
?	7.����
?	8.����
?	9.����
?	10.����
?	11.������
?	12.�����˳�
?	����Ա�˺�Ϊadmin ����: 123

?	�ȴ���һ��user.txt����û���Ϣ

?	�������ļ��ŵ�bank�ļ�����

```python
?```
### ����һ����main��.py�ļ�
"""
����:Person
����:���������֤�š��ֻ��š���

����:card
����:���š����롢���

����:View
����:��

����:ATM������
"""

from bank.view import View
from bank.operation import Operation
# ��ʵ������ʾ�������
v = View()

# ������
def main():
    # ������ʾ��������еĹ���Ա��¼����
    v.login()
    # ���ù��ܵ����еĳ�ʼ������(��ӡÿ���˻���Ϣ, ����鿴)
    o = Operation()
    while View.a:
        choice = input("��ѡ����Ҫ�ķ�����Ŀ:")
        # ѡ����Ŀ1, ���ù������е�ע�᷽�������淽��
        if choice == "1":
            o.register()
            o.exit()
        # ѡ����Ŀ2, ���ù������еĲ�ѯ���������淽��
        elif choice == "2":
            o.query()
            o.exit()
        # ѡ����Ŀ3, ���ù������еĴ�Ǯ���������淽��
        elif choice == "3":
            o.save_money()
        # ѡ����Ŀ4, ���ù������е�ȡǮ���������淽��
        elif choice == "4":
            o.draw_money()
            o.exit()
        # ѡ����Ŀ5, ���ù������е�ת�˷��������淽��
        elif choice == "5":
            o.trans_money()
            o.exit()
        # ѡ����Ŀ6, ���ù������еĸ��ܷ��������淽��
        elif choice == "6":
            o.change_password()
            o.exit()
        # ѡ����Ŀ7, ���ù������е��������������淽��
        elif choice == "7":
            o.lock()
            o.exit()
        # ѡ����Ŀ8, ���ù������еĽ������������淽��
        elif choice == "8":
            o.unlock()
            o.exit()
        # ѡ����Ŀ9, ���ù������еĲ������������淽��
        elif choice == "9":
            o.replace()
            o.exit()
        # ѡ����Ŀ10, ���ù������е��������������淽��
        elif choice == "10":
            o.remove()
            o.exit()
        # ѡ����Ŀ11, ���ù������е������뷽�������淽��
        elif choice == "11":
            o.Save_monet()
            o.exit()
        # ѡ����Ŀ0, ���ù������б��淽��������ѭ��
        elif choice == "0":
            o.exit()
            break
        # �������Ŀ�������
        else:
            print("��������������ѡ��")


if __name__ == '__main__':
    main()
?```
```

```python
?```
��### ����һ����view.py���ļ�
������һ����ʾ�������

���������е�¼����Ա�˺ŵķ�������ʾ���ܵķ���




from time import sleep
class View:

    a = 0



    def login��self����

        name = input�������������Ա�˺ţ�����

        pwd = input�������������Ա���룺����

        ���name ==��admin����pwd ==��123����

            self.login_view����

            sleep��0.5��

            self.opration_view����

            View.a = 1

        ������

            ��ӡ�� ���˺Ż����벻��ȷ����



    def login_view��self����

        ��ӡ����************************************����

        ��ӡ����*                                  *����

        ��ӡ����*                                  *����

        ��ӡ����*                   ATM            *����

        ��ӡ����*                                  *����

        ��ӡ����*                                  *����

        ��ӡ����************************************����



    def opration_view��self����

        ��ӡ����************************************����

        print����*          1.����      2.��ѯ      *����

        print����*          3.��Ǯ      4.ȡǮ      *����

        print����*          5.ת��      6.����      *����

        print����*          7.����      8.����      *����

        print����*          9.����      10.����     *")
        print����*         11.�����루��Ҫ��֤��    *����

        print����*         12.�����˳�              *����
 ```
```

```python
?```
### ����һ����person.py���ļ�
# �����˵���
# �˵��������û���, ���֤����, �ֻ���, ��
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
### ����һ����card.py���ļ�
# ����������
# ���������� ����, ����, ���, �Ƿ��������ж�
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
### ����һ����operation.py���ļ�
""""""
import pickle
import os
import random
from bank.card import Card
from bank.person import Person

"""
�����ǵ�һ�δ�ϵͳ��ʱ��   �ֵ�Ϊ��
�ٴδ�ϵͳʱ   �Զ��������е��û�
"""


# ����һ��������
class Operation:
    # ��ʼ������, ��ӡ���е��û���Ϣ
    def __init__(self):
        try:
            self.load_user()
            print(self.user_dict)
        except BaseException:
            print('ִ�д���, ����ɾ��user.txt�ļ�')
            exit()

    # �����û���Ϣ
    def load_user(self):
        # �ж��ļ��Ƿ����
        if os.path.exists("user.txt"):
            with open("user.txt", "rb") as f:
                self.user_dict = pickle.load(f)
        # �������򴴽�һ�����ֵ�
        else:
            self.user_dict = {}

    # ע��
    def register(self):
        while True:
            # ��������
            name = input("��������������:")
            # ����û�������������ĸ�������
            if name.isalnum():
                # ����ѭ��
                break
            else:
                print('������ʽ����')
        # �������֤��
        a = True
        while a:
            userid = input("�������������֤��:")
            # ������֤��������ʮ�����������
            if userid.isdigit():
                # ����û���Ϣ���ļ�����
                if os.path.exists('user.txt'):
                    # �������еĿ���
                    for var in range(100000, 1000000):
                        # ͨ�����ŵõ�ֵ
                        p = self.user_dict.get(var, 10)
                        if p == 10:
                            pass
                        else:
                            # ������������֤�����Ѿ�����
                            if p.userid == userid:
                                print('���֤�����ظ�')
                                break
                            else:
                                pass
                        if var == 999999:
                            a = False
                else:
                    break
            else:
                print('���֤�Ÿ�ʽ����')
        # �����ֻ���
        while True:
            phone = input("�����������ֻ���:")
            # ����ֻ�������ʮ�����������
            if phone.isdigit():
                break
            else:
                print('�ֻ��Ÿ�ʽ����')
        # ��������  ȷ������
        password = self.get_pwd()
        # ���ɿ���
        cardid = self.get_cardid()
        # ��ȡһ�ſ�
        card = Card(cardid, password, 10)
        # ͨ�����ҵ��û�
        user = Person(name, userid, phone, card)
        # �����û���Ϣ
        self.user_dict[cardid] = user
        print("��ϲ%s�����ɹ�,���Ŀ���Ϊ:%s,�������%sԪ" % (name, cardid, card.money))

    # ��������
    def get_pwd(self):
        while True:
            pwd1 = input("��������������:")
            # �����������������ĸ�������
            if pwd1.isalnum():
                # �ٴ���������
                pwd2 = input("��ȷ����������:")
                # �������������ͬ
                if pwd1 == pwd2:
                    # ��������
                    return pwd1
                else:
                    print("�������벻һ�£�����������")
            else:
                print('�����ʽ����')

    # �����������
    def get_cardid(self):
        while True:
            # ��������ɿ���
            cardid = random.randint(100000, 999999)
            # ������Ų�����
            if cardid not in self.user_dict:
                return cardid

    # ��ѯ
    def query(self):
        # �õ�һ�ſ�
        card = self.get_card_info()
        if not card:
            print("��������!")
        # �жϿ��Ƿ�����
        else:
            if card.islock:
                print("����������!")
            else:
                # ��⿨������
                lock = self.check_pwd(card)
                if lock:
                    print("�������%sԪ!" % card.money)

    # �������
    def check_pwd(self, card):
        # ��¼��������εĲ���
        count = 1
        while count < 4:
            pwd = input("��������������:")
            # �ж��û�����������Ƿ�Ϳ��ڵ�����һ��
            if pwd == card.password:
                return True
            else:
                # ��һ�������+1
                count += 1
                if count == 4:
                    # ����
                    card.islock = True
                    print("������������ʧ�ܣ����Ѿ�������!")

    # ��ȡ����Ϣ
    def get_card_info(self):
        # �û����뿨��
        cardid = input("���������Ŀ���:")
        # �����������ʮ�����������
        if cardid.isdigit():
            cardid = int(cardid)
            if 100000 <= cardid <= 999999:
                # �жϿ����Ƿ����
                if cardid not in self.user_dict:
                    return False
                else:
                    # ͨ�������ҵ��û�  �洢��ʽ��:user_dict[cardid] = user
                    user = self.user_dict[cardid]
                    # ͨ���û��ҵ���
                    card = user.card
                    return card

    # ��Ǯ
    def save_money(self):
        # �õ�һ�ſ�
        card = self.get_card_info()
        if not card:
            print("��������!")
        else:
            # �ж��Ƿ�����
            if not card.islock:
                # ��������
                money = input("����������:")
                # ����������ʮ�����������
                if money.isdigit():
                    # Ǯ <= 0
                    if int(money) <= 0:
                        print("����Ľ���ȷ!")
                    else:
                        # �ÿ����������money
                        card.money += int(money)
                        print("���ɹ�,�������Ϊ%sԪ" % card.money)
                else:
                    print('��ʽ����')
            else:
                print("���Ѿ������������Ƚ⿨!")

    # ȡǮ
    def draw_money(self):
        # �õ�һ�ſ�
        card = self.get_card_info()
        if not card:
            print("��������!")
        else:
            # �ж��Ƿ�����
            if not card.islock:
                pwd = input('����������: ')
                # ������ͬ
                if pwd == card.password:
                    # ����ȡ����
                    money = input("������ȡ����:")
                    # ����������ʮ�����������
                    if money.isdigit():
                        # �������������
                        if int(money) <= 0 or int(money) > card.money:
                            print("����Ľ���ȷ!")
                        else:
                            # �ÿ���������money
                            card.money -= int(money)
                            print("ȡ��ɹ�,�������Ϊ%sԪ" % card.money)
                    else:
                        print('��ʽ����')
                else:
                    print('�����������!')
            else:
                print("���Ѿ������������Ƚ⿨!")

    # ������
    def change_password(self):
        # ��ȡ��
        card = self.get_card_info()
        if not card:
            print("��������!")
        else:
            # �ж��Ƿ�����
            if card.islock:
                print("���ѱ�����,���Ƚ�����")
            else:
                # ���ü������ķ���
                self.check_pwd(card)
                # �ж��Ƿ�����
                if card.islock:
                    print("���ѱ�����,���Ƚ�����")
                else:
                    while True:
                        # ����������
                        pwd3 = input("����������������:")
                        # �ж������Ƿ������ֺ�����ĸ���
                        if pwd3.isalnum():
                            pwd4 = input("��ȷ������������:")
                            # ����������ͬ
                            if pwd3 == pwd4:
                                # �ж��������Ƿ��ԭ������ͬ
                                if pwd3 != card.password:
                                    # �������
                                    card.password = pwd3
                                    print('�������óɹ�!')
                                    break
                                else:
                                    print('�����������ԭ������ͬ, ����������')
                            else:
                                print("�������벻һ�£�����������")
                        else:
                            print('�����ʽ����')

    # ����
    def lock(self):
        # ��ȡ��
        card = self.get_card_info()
        if not card:
            print('��������')
        else:
            # �ж��Ƿ�����
            if card.islock == False:
                # ���ü�����뷽��
                if self.check_pwd(card):
                    card.islock = True
                    print('�����ɹ�')
            else:
                print('���Ѿ�������!')

    # ת��
    def trans_money(self):
        # ���õ�һ�ſ�
        card = self.get_card_info()
        if not card:
            print("��������!")
        else:
            # �жϿ��Ƿ���
            if card.islock:
                print("���ѱ�����,���Ƚ�����")
            else:
                # ���ü������ķ���
                if self.check_pwd(card):
                    # ��ȡ�տ����
                    otherid = int(input("������Է��˺�:"))
                    # �ж϶Է������Ƿ����
                    if otherid not in self.user_dict or otherid == card.cardid:
                        print("����!!��")
                    else:
                        # �ж��Ƿ���
                        if card.islock:
                            print("���ѱ�����,���Ƚ�����")
                        else:
                            # ���ת���û�
                            user = self.user_dict[card.cardid]
                            # �����ת���û�
                            other_user = self.user_dict[otherid]
                            # �����ת���û��Ŀ���
                            other_card = other_user.card
                            # ����ת�˽��
                            money = input("������ת�˽��:")
                            # ����������
                            if money.isdigit():
                                money = int(money)
                                if money > 0 and  money <= card.money:
                                    # ˫����������
                                    card.money -= money
                                    other_card.money += money
                                    print("%s��%s�ɹ�ת��%sԪ��" % (
                                        user.name, other_user.name, money
                                    ))
                                else:
                                    print("ת�˽������!")
                            else:
                                print('��ʽ����')

    # ����
    def unlock(self):
        # �õ�һ�ſ�
        card = self.get_card_info()
        if not card:
            print("��������!")
        else:
            # ����û�
            user = self.user_dict[card.cardid]
            # �ж��Ƿ��Ѿ�������
            if card.islock == False:
                print('���ѱ�����, �����ٴν���')
            else:
                while True:
                    # ��������
                    pwd = input("����������:")
                    # �����Ƿ���ͬ
                    if pwd == card.password:
                        # ����
                        card.islock = False
                        print("��ϲ�������ɹ�!")
                        break
                    else:
                        # ���벻��ͬ���������֤����
                        userid = input("�������������֤��:")
                        # �ж����֤�����Ƿ�һ��
                        if userid == user.userid:
                            # ������������
                            pwd1 = self.get_pwd()
                            card.password = pwd1
                        else:
                            print("���֤������")
                            break

    # ����
    def replace(self):
        # �������֤����
        Userid = input('������������֤: ')
        # ���֤�����������
        if Userid.isdigit():
            # �������п���
            for var in range(100000, 1000000):
                # ����ֵ
                p = self.user_dict.get(var, 10)
                if p == 10:
                     pass
                else:
                    # �ж����֤�����Ƿ���ͬ
                    if p.userid == Userid:
                        # print(var)
                        # ��ѯ���û�
                        user = self.user_dict[var]
                        # �������ɿ���
                        cardid = self.get_cardid()
                        # ���Ÿ���
                        user.card.cardid = cardid
                        # ��ԭ���Ŷ�Ӧ���û���Ϣ��ֵ���¿��Ŷ�Ӧ���û���Ϣ
                        self.user_dict[cardid] = self.user_dict[var]
                        # ɾ��ԭ�û�
                        self.user_dict.pop(var)
                        print('�����ɹ�, ����¿�����%s' % cardid)
                        print(self.user_dict)
                        break
                if var == 999999:
                    print('���֤��������')
        else:
            print('���֤�Ÿ�ʽ����ȷ')

    # ����
    def remove(self):
        # �õ���
        card = self.get_card_info()
        # ���ü�����뷽��
        lock = self.check_pwd(card)
        # �ж������Ƿ�������ȷ
        if lock:
            # ɾ�����ż��û���Ϣ
            self.user_dict.pop(card.cardid)
            print('�����ɹ�')
            print(self.user_dict)
        else:
            print('�������벻��ȷ')

    # ������
    def Save_monet(self):
        # ��ӡ����ѡ������
        print('1. ��Ԫ    1��Ԫ���Դ���6.8�����')
        print('2. ŷԪ    1ŷԪ���Դ���7.9�����')
        choice = input('���������: ')
        # ѡ�����1
        if choice == '1':
            # �õ���
            card = self.get_card_info()
            if not card:
                print("��������!")
            else:
                # �ж��Ƿ�����
                if not card.islock:
                    # ��������
                    money = input("����������:")
                    # ����Ƿ���Ϲ���
                    if money.isdigit():
                        money = int(money)
                        if money <= 0:
                            print("����Ľ���ȷ!")
                        else:
                            a = True
                            while a:
                                # ������֤��
                                yzm = random.choice('abcdefghijklmnopqrstuvwxyz0123456789') + random.choice('abcdefghijklmnopqrstuvwxyz0123456789') + random.choice('abcdefghijklmnopqrstuvwxyz0123456789') + random.choice('abcdefghijklmnopqrstuvwxyz')
                                print('��֤����', yzm)
                                # ������֤��
                                num1 = input('��������֤��: ')
                                # ��֤����ͬ
                                if yzm == num1:
                                    # �ÿ����������money
                                    card.money += (money * 6.8)
                                    print("���ɹ�,�������Ϊ%sԪ" % card.money)
                                    a = False
                                else:
                                    print('��֤�����')
                    else:
                        print('��ʽ����')
                else:
                    print("���Ѿ������������Ƚ⿨!")
        # ���2
        elif choice == '2':
            # ��ÿ�
            card = self.get_card_info()
            if not card:
                print("��������!")
            else:
                # �ж��Ƿ�����
                if not card.islock:
                    # ��������
                    money = input("����������:")
                    # �жϽ���Ƿ���Ϲ���
                    if money.isdigit():
                        money = int(money)
                        if money <= 0:
                            print("����Ľ���ȷ!")
                        else:
                            a = True
                            while a:
                                # ��֤������
                                yzm = random.choice('abcdefghijklmnopqrstuvwxyz0123456789') + random.choice('abcdefghijklmnopqrstuvwxyz0123456789') + random.choice('abcdefghijklmnopqrstuvwxyz0123456789') + random.choice('abcdefghijklmnopqrstuvwxyz')
                                print('��֤����', yzm)
                                # ��֤����ͬ
                                num1 = input('��������֤��: ')
                                if yzm == num1:
                                    # �ÿ����������money
                                    card.money += (money * 7.9)
                                    print("���ɹ�,�������Ϊ%sԪ" % card.money)
                                    a = False
                                else:
                                    print('��֤�����')
                    else:
                        print('��ʽ����')
                else:
                    print("���Ѿ������������Ƚ⿨!")
        else:
            print('����')

    # ����
    def exit(self):
        # ����д�뱣���û���Ϣ���ļ�
        with open("user.txt", "wb") as f:
            pickle.dump(self.user_dict, f)
?```
```