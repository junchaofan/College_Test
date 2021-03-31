package frame;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.ButtonGroup;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JRadioButton;
import javax.swing.JTextField;
import javax.swing.border.EmptyBorder;

import model.Librarian;
import model.Reader;
import sqlTools.LibrarianTools;
import sqlTools.ReaderTools;

public class Login extends JFrame implements ItemListener {

	/**
	 * Java的序列化机制是通过在运行时判断类的serialVersionUID来验证版本一致性的
	 */
	private static final long serialVersionUID = 1L;
	private JPanel contentPane;

	private boolean readerLogin = true;
	private boolean librarianLogin = false;
	public static String idReader;
	public static String nameReader;
	public static String nameUser;
	private Librarian lib;
	private Reader reader;

	private JTextField nameUserTextField;
	private JPasswordField passwordField;
	private JButton loginButton;
	private JButton view_Password_Button;

	private JRadioButton readerRadioButton;
	private JRadioButton librarianRadioButton;
	private ButtonGroup group;

	private JLabel userNameLabel;
	private JLabel passwordLabel;

	public Login() {
		setResizable(false);
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setBounds(100, 100, 389, 560);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);

		userNameLabel = new JLabel("用户名");
		userNameLabel.setForeground(Color.WHITE);
		userNameLabel.setFont(new Font("Dialog", Font.BOLD, 15));
		userNameLabel.setBounds(64, 188, 55, 20);
		contentPane.add(userNameLabel);

		passwordLabel = new JLabel("密码");
		passwordLabel.setForeground(Color.WHITE);
		passwordLabel.setFont(new Font("Dialog", Font.BOLD, 15));
		passwordLabel.setBounds(64, 267, 55, 18);
		contentPane.add(passwordLabel);

		nameUserTextField = new JTextField();
		nameUserTextField.setFont(new Font("Dialog", Font.PLAIN, 15));
		nameUserTextField.setBounds(128, 188, 167, 22);
		contentPane.add(nameUserTextField);
		nameUserTextField.setColumns(10);

		passwordField = new JPasswordField();
		passwordField.setFont(new Font("Dialog", Font.PLAIN, 15));
		passwordField.setBounds(128, 265, 167, 22);
		contentPane.add(passwordField);

		loginButton = new JButton(new ImageIcon("image/loginbutton.jpg"));
		loginButton.setFont(new Font("Dialog", Font.BOLD, 17));
		loginButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				check_login();
			}
		});
		loginButton.setBounds(129, 386, 98, 36);
		contentPane.add(loginButton);

		// 为单选按钮JRadioButton加上事件监听，默认选中readerRadioButton
		readerRadioButton = new JRadioButton("读者");
		readerRadioButton.setForeground(Color.BLACK);
		readerRadioButton.setBounds(67, 308, 121, 36);
		contentPane.add(readerRadioButton);
		readerRadioButton.addItemListener(this);
		readerRadioButton.setSelected(true);
		readerRadioButton.setContentAreaFilled(false);

		librarianRadioButton = new JRadioButton("管理员");
		librarianRadioButton.setForeground(Color.BLACK);
		librarianRadioButton.setBounds(208, 308, 121, 36);
		contentPane.add(librarianRadioButton);
		librarianRadioButton.addItemListener(this);
		librarianRadioButton.setContentAreaFilled(false);
		
		// 将单选按钮加入到一个组里
		group = new ButtonGroup();
		group.add(this.readerRadioButton);
		group.add(this.librarianRadioButton);
		
		view_Password_Button = new JButton(new ImageIcon("image/review.jpg"));
		view_Password_Button.setBounds(302, 260, 31, 30);
		view_Password_Button.addMouseListener(new MouseAdapter(){
		char echoChar=passwordField.getEchoChar();
			public void mousePressed(MouseEvent e){
				passwordField.setEchoChar((char)0);
			}
			public void mouseReleased(MouseEvent e){
				passwordField.setEchoChar(echoChar);
				passwordField.requestFocus();				
			}
		});
		contentPane.add(view_Password_Button);
		
		JLabel background1 = new JLabel(new ImageIcon("image/Login.jpg"));
		background1.setBounds(0, 0, 383, 485);
		contentPane.add(background1);
		
	}

	private void check_login() {
		if (this.readerLogin == true) {
			ReaderTools rTools = new ReaderTools();
			reader = new Reader();
			reader.setIdReader(nameUserTextField.getText());
			reader.setPassword(new String(passwordField.getPassword()));
			if (nameUserTextField.getText() != null && !"".equals(nameUserTextField.getText())
					&& passwordField.getPassword() != null && !("".equals(new String(passwordField.getPassword())))) {

				boolean whether_login = rTools.ReaderLogin(reader.getIdReader(), reader.getPassword());
				nameReader = rTools.ReaderData(reader.getIdReader()).get(0).getNameReader();
				if (whether_login == true) {
					idReader = reader.getIdReader();
					ReaderFrame frame = new ReaderFrame();
					new Thread(frame,"Reader线程").start();
					CloseFrame();
					return;
				} else {
					JOptionPane.showMessageDialog(this, "用户名或密码错误", "", JOptionPane.WARNING_MESSAGE);
					return;
				}

			} else {
				JOptionPane.showMessageDialog(this, "请填写用户名和密码", "", JOptionPane.WARNING_MESSAGE);
				return;
			}

		}
		if (this.librarianLogin == true) {
			LibrarianTools libTools = new LibrarianTools();
			lib = new Librarian();
			lib.setNameUser(nameUserTextField.getText());
			lib.setPassword(new String(passwordField.getPassword()));
			if (nameUserTextField.getText() != null && !"".equals(nameUserTextField.getText())
					&& passwordField.getPassword() != null && !("".equals(new String(passwordField.getPassword())))) {

				boolean whether_login = libTools.LibrarianLogin(lib.getNameUser(), lib.getPassword());
				if (whether_login == true) {
					nameUser = lib.getNameUser();
					LibrarianFrame frame = new LibrarianFrame();
					new Thread(frame,"Worker线程").start();
					CloseFrame();
					return;
				} else {
					JOptionPane.showMessageDialog(this, "用户名或密码错误", "", JOptionPane.WARNING_MESSAGE);
					return;
				}

			} else {
				JOptionPane.showMessageDialog(this, "请填写用户名和密码", "", JOptionPane.WARNING_MESSAGE);
				return;
			}
		}
	}


	public void itemStateChanged(ItemEvent e) {
		if (e.getSource() == readerRadioButton) {
			this.readerLogin = true;
			this.librarianLogin = false;
		} else {
			this.readerLogin = false;
			this.librarianLogin = true;
		}
	}
	public void CloseFrame() {
		super.dispose();
	}
}
