package frame;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.border.EmptyBorder;

import model.Reader;
import sqlTools.ReaderTools;
import java.awt.Color;
import java.awt.Font;

public class Reader_Update extends JFrame {

	/**
	 * Java�����л�������ͨ��������ʱ�ж����serialVersionUID����֤�汾һ���Ե�
	 */
	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	
	private JTextField nameReadertextField;
	private JTextField typetextField;
	private JTextField passwordtextField;	

	private JLabel nameReaderLabel;
	private JLabel typeLabel;
	private JLabel passwordLabel;
	private JButton updateButton;
	
	public Reader_Update(Book_AllReader all_readerFrame) {
		setResizable(false);
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setBounds(100, 100, 996, 699);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel NameLabel = new JLabel("��Ϣ�޸�");
		NameLabel.setForeground(Color.BLACK);
		NameLabel.setFont(new Font("Dialog", Font.BOLD, 40));
		NameLabel.setBounds(520, 120, 200, 40);
		contentPane.add(NameLabel);
		
		JButton reader_Registerbutton = new JButton("����ע��");
		reader_Registerbutton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Reader_Register reader_RegisterFrame = new Reader_Register();
				reader_RegisterFrame.setVisible(true);
				CloseFrame();
			}
		});
		reader_Registerbutton.setBounds(60, 197, 123, 29);
		contentPane.add(reader_Registerbutton);

		JButton book_Registerbutton = new JButton("�鼮���");
		book_Registerbutton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Book_Register book_RegisterFrame = new Book_Register();
				book_RegisterFrame.setVisible(true);
				CloseFrame();
			}
		});
		book_Registerbutton.setBounds(60, 292, 123, 29);
		contentPane.add(book_Registerbutton);

		JButton all_Readerbutton = new JButton("���߹���");
		all_Readerbutton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Book_AllReader all_ReaderFrame = new Book_AllReader();
				all_ReaderFrame.setVisible(true);
				CloseFrame();
			}
		});
		all_Readerbutton.setBounds(60, 375, 123, 29);
		contentPane.add(all_Readerbutton);

		JButton all_Bookbutton = new JButton("������");
		all_Bookbutton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Book_AllBook all_BookFrame = new Book_AllBook();
				all_BookFrame.setVisible(true);
				CloseFrame();
			}
		});
		all_Bookbutton.setBounds(60, 459, 123, 29);
		contentPane.add(all_Bookbutton);

		JButton checkReader_button = new JButton("���Ĺ���");
		checkReader_button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				CheckReaderFrame checkReaderFrame = new CheckReaderFrame();
				checkReaderFrame.setVisible(true);
				CloseFrame();
			}
		});
		checkReader_button.setBounds(60, 545, 123, 29);
		contentPane.add(checkReader_button);

		JButton log_out_Button = new JButton("�ǳ�");
		log_out_Button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Login loginframe = new Login();
				loginframe.setVisible(true);
				CloseFrame();
			}
		});
		log_out_Button.setBounds(817, 102, 85, 29);
		contentPane.add(log_out_Button);

		
		passwordLabel = new JLabel("����");
		passwordLabel.setFont(new Font("����", Font.PLAIN, 30));
		passwordLabel.setBounds(470, 240, 113, 34);
		contentPane.add(passwordLabel);

		nameReaderLabel = new JLabel("����");
		nameReaderLabel.setFont(new Font("����", Font.PLAIN, 30));
		nameReaderLabel.setBounds(470, 320, 90, 34);
		contentPane.add(nameReaderLabel);

		typeLabel = new JLabel("��ϵ��ʽ");
		typeLabel.setFont(new Font("����", Font.PLAIN, 30));
		typeLabel.setBounds(445, 400, 120, 55);
		contentPane.add(typeLabel);
		
		passwordtextField = new JTextField();
		passwordtextField.setFont(new Font("����", Font.PLAIN, 30));
		passwordtextField.setBounds(640, 240, 137, 47);
		contentPane.add(passwordtextField);
		passwordtextField.setColumns(20);

		nameReadertextField = new JTextField();
		nameReadertextField.setFont(new Font("����", Font.PLAIN, 30));
		nameReadertextField.setBounds(640, 320, 139, 47);
		contentPane.add(nameReadertextField);
		nameReadertextField.setColumns(20);

		typetextField = new JTextField();
		typetextField.setFont(new Font("����", Font.PLAIN, 30));
		typetextField.setBounds(640, 400, 200, 47);
		contentPane.add(typetextField);
		typetextField.setColumns(20);

	
		updateButton = new JButton(new ImageIcon("image/update.jpg"));
		updateButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				do_updateButton_UpdateReader();
			}
		});
		updateButton.setBounds(555, 545, 106, 47);
		contentPane.add(updateButton);

		JLabel background1 = new JLabel(new ImageIcon("image/background1.jpg"));
		background1.setBounds(0, 0, 990, 659);
		contentPane.add(background1);
		
	}

	protected void do_updateButton_UpdateReader() {
		ReaderTools readerTools = new ReaderTools();
		Reader reader = readerTools.getNewreader();
		if(nameReadertextField.getText() != null && !"".equals(nameReadertextField.getText()))
			reader.setNameReader(nameReadertextField.getText());
		if(typetextField.getText() != null && !"".equals(typetextField.getText()))
			reader.setType(typetextField.getText());
		if(passwordtextField.getText() != null && !"".equals(passwordtextField.getText()))
			reader.setPassword(passwordtextField.getText());
		int i = readerTools.UpdateReader(reader);
		if ( i == 1 ) {
			JOptionPane.showMessageDialog(getContentPane(), "�ɹ�����������Ϣ��", "", JOptionPane.WARNING_MESSAGE);
	        return;
		} else {
			JOptionPane.showMessageDialog(getContentPane(), "����������Ϣʧ�ܣ�", "", JOptionPane.WARNING_MESSAGE);
	        return;
		}
	}
	
	public void CloseFrame() {
		super.dispose();
	}
}
