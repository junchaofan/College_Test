package frame;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.math.BigDecimal;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.border.EmptyBorder;

import model.Book;
import sqlTools.BookTools;

public class Book_Register extends JFrame {

	/**
	 * Java的序列化机制是通过在运行时判断类的serialVersionUID来验证版本一致性的
	 */
	private static final long serialVersionUID = 1L;
	private JPanel contentPane;

	private JTextField idBooktextField;
	private JTextField nameBooktextField;
	private JTextField priceField;
	private JTextField authortextField;
	private JLabel idBookLabel;
	private JLabel nameBookLabel;
	private JLabel priceLabel;
	private JLabel authorLabel;
	private JButton insertButton;

	public Book_Register() {
		setResizable(false);
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setBounds(100, 100, 996, 699);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel NameLabel = new JLabel("书籍入库");
		NameLabel.setForeground(Color.BLACK);
		NameLabel.setFont(new Font("Dialog", Font.BOLD, 40));
		NameLabel.setBounds(520, 120, 200, 40);
		contentPane.add(NameLabel);

		JButton reader_Registerbutton = new JButton("读者注册");
		reader_Registerbutton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Reader_Register reader_RegisterFrame = new Reader_Register();
				reader_RegisterFrame.setVisible(true);
				CloseFrame();
			}
		});
		reader_Registerbutton.setBounds(60, 197, 123, 29);
		contentPane.add(reader_Registerbutton);

		JButton book_Registerbutton = new JButton("书籍入库");
		book_Registerbutton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Book_Register book_RegisterFrame = new Book_Register();
				book_RegisterFrame.setVisible(true);
				CloseFrame();
			}
		});
		book_Registerbutton.setBounds(60, 292, 123, 29);
		contentPane.add(book_Registerbutton);

		JButton all_Readerbutton = new JButton("读者管理");
		all_Readerbutton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Book_AllReader all_ReaderFrame = new Book_AllReader();
				all_ReaderFrame.setVisible(true);
				CloseFrame();
			}
		});
		all_Readerbutton.setBounds(60, 375, 123, 29);
		contentPane.add(all_Readerbutton);

		JButton all_Bookbutton = new JButton("书库管理");
		all_Bookbutton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Book_AllBook all_BookFrame = new Book_AllBook();
				all_BookFrame.setVisible(true);
				CloseFrame();
			}
		});
		all_Bookbutton.setBounds(60, 459, 123, 29);
		contentPane.add(all_Bookbutton);

		JButton checkReader_button = new JButton("还书申请");
		checkReader_button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				CheckReaderFrame checkReaderFrame = new CheckReaderFrame();
				checkReaderFrame.setVisible(true);
				CloseFrame();
			}
		});
		checkReader_button.setBounds(60, 545, 123, 29);
		contentPane.add(checkReader_button);

		JButton log_out_Button = new JButton("登出");
		log_out_Button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Login loginframe = new Login();
				loginframe.setVisible(true);
				CloseFrame();
			}
		});
		log_out_Button.setBounds(817, 102, 85, 29);
		contentPane.add(log_out_Button);

		idBookLabel = new JLabel("书籍编号");
		idBookLabel.setFont(new Font("宋体", Font.PLAIN, 30));
		idBookLabel.setBounds(448, 163, 131, 51);
		contentPane.add(idBookLabel);

		nameBookLabel = new JLabel("书名");
		nameBookLabel.setFont(new Font("宋体", Font.PLAIN, 30));
		nameBookLabel.setBounds(469, 229, 81, 51);
		contentPane.add(nameBookLabel);

		priceLabel = new JLabel("价格");
		priceLabel.setFont(new Font("宋体", Font.PLAIN, 30));
		priceLabel.setBounds(469, 292, 81, 51);
		contentPane.add(priceLabel);

		authorLabel = new JLabel("作者");
		authorLabel.setFont(new Font("宋体", Font.PLAIN, 30));
		authorLabel.setBounds(469, 358, 81, 44);
		contentPane.add(authorLabel);

		idBooktextField = new JTextField();
		idBooktextField.setFont(new Font("宋体", Font.PLAIN, 30));
		idBooktextField.setBounds(594, 168, 131, 41);
		contentPane.add(idBooktextField);
		idBooktextField.setColumns(10);
		idBooktextField.setEditable(true);
		idBooktextField.setText(String.format("%06d",new BookTools().return_TSBH()+1));
		idBooktextField.setEditable(false);

		nameBooktextField = new JTextField();
		nameBooktextField.setFont(new Font("宋体", Font.PLAIN, 30));
		nameBooktextField.setBounds(594, 236, 131, 37);
		contentPane.add(nameBooktextField);
		nameBooktextField.setColumns(10);

		priceField = new JTextField();
		priceField.setFont(new Font("宋体", Font.PLAIN, 30));
		priceField.setBounds(594, 299, 131, 37);
		contentPane.add(priceField);
		priceField.setColumns(10);

		authortextField = new JTextField();
		authortextField.setFont(new Font("宋体", Font.PLAIN, 30));
		authortextField.setBounds(594, 365, 131, 37);
		contentPane.add(authortextField);
		authortextField.setColumns(10);

		insertButton = new JButton(new ImageIcon("image/new.jpg"));
		insertButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				do_insertButton_AddBook();
			}
		});
		insertButton.setBounds(544, 582, 106, 44);
		contentPane.add(insertButton);

		JLabel background1 = new JLabel(new ImageIcon("image/background1.jpg"));
		background1.setBounds(0, 0, 990, 659);
		contentPane.add(background1);
	}

	protected void do_insertButton_AddBook() {

		BookTools bookTools = new BookTools();
		Book book = new Book();
		book.setIdBook(String.format("%06d",new BookTools().return_TSBH()+1));
		bookTools.setNewbook(book);
		if (nameBooktextField.getText() != null && !"".equals(nameBooktextField.getText()))
			book.setNameBook(nameBooktextField.getText());	
		if (priceField.getText() != null && !"".equals(priceField.getText()))
			book.setPrice(new BigDecimal(priceField.getText()));
		if (authortextField.getText() != null && !"".equals(authortextField.getText())) {
			book.setAuthor(authortextField.getText());
			book.setType(false);
			int i = bookTools.AddBook(book);
			if (i == 1) {
				JOptionPane.showMessageDialog(getContentPane(), "成功新增图书信息！", "", JOptionPane.WARNING_MESSAGE);
				return;
			} else {
				JOptionPane.showMessageDialog(getContentPane(), "新增图书信息失败！", "", JOptionPane.WARNING_MESSAGE);
				return;
			}
		} else {
			JOptionPane.showMessageDialog(getContentPane(), "请输入完整资料", "", JOptionPane.WARNING_MESSAGE);
			return;
		}
	}

	public void CloseFrame() {
		super.dispose();
	}
}
