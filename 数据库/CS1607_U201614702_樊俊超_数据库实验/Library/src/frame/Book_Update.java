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

public class Book_Update extends JFrame {

	/**
	 * Java的序列化机制是通过在运行时判断类的serialVersionUID来验证版本一致性的
	 */
	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	
	private JTextField nameBooktextField;
	private JTextField priceField;
	private JTextField authortextField;
	private JLabel idBookLabel;
	private JLabel idBook_showLabel;
	private JLabel nameBookLabel;
	private JLabel priceLabel;
	private JLabel authorLabel;
	private JButton updateButton;
	/**
	 * Create the frame.
	 */
	public Book_Update(Book_AllBook all_BookFrame) {
		setResizable(false);
		this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setBounds(100, 100, 608, 743);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		idBookLabel = new JLabel("书籍编号");
		idBookLabel.setForeground(Color.BLACK);
		idBookLabel.setFont(new Font("宋体", Font.PLAIN, 30));
		idBookLabel.setBounds(137, 111, 137, 39);
		contentPane.add(idBookLabel);
		
		nameBookLabel = new JLabel("书名");
		nameBookLabel.setForeground(Color.BLACK);
		nameBookLabel.setFont(new Font("宋体", Font.PLAIN, 30));
		nameBookLabel.setBounds(137, 190, 103, 39);
		contentPane.add(nameBookLabel);
		
		priceLabel = new JLabel("价格");
		priceLabel.setForeground(Color.BLACK);
		priceLabel.setFont(new Font("宋体", Font.PLAIN, 30));
		priceLabel.setBounds(137, 256, 81, 39);
		contentPane.add(priceLabel);
		
		authorLabel = new JLabel("作者");
		authorLabel.setForeground(Color.BLACK);
		authorLabel.setFont(new Font("宋体", Font.PLAIN, 30));
		authorLabel.setBounds(137, 322, 81, 39);
		contentPane.add(authorLabel);
		
		idBook_showLabel = new JLabel();
		idBook_showLabel.setFont(new Font("宋体", Font.PLAIN, 30));
		idBook_showLabel.setForeground(Color.BLACK);
		idBook_showLabel.setBounds(307, 112, 117, 37);
		contentPane.add(idBook_showLabel);
		idBook_showLabel.setText(all_BookFrame.bookJtable.getValueAt(all_BookFrame.row, 0).toString());
		
		nameBooktextField = new JTextField();
		nameBooktextField.setFont(new Font("宋体", Font.PLAIN, 30));
		nameBooktextField.setBounds(307, 191, 113, 37);
		contentPane.add(nameBooktextField);
		nameBooktextField.setColumns(10);
		nameBooktextField.setText(all_BookFrame.bookJtable.getValueAt(all_BookFrame.row, 1).toString());
		
		priceField = new JTextField();
		priceField.setFont(new Font("宋体", Font.PLAIN, 30));
		priceField.setBounds(307, 256, 117, 39);
		contentPane.add(priceField);
		priceField.setColumns(10);
		priceField.setText(all_BookFrame.bookJtable.getValueAt(all_BookFrame.row, 2).toString());
		
		authortextField = new JTextField();
		authortextField.setFont(new Font("宋体", Font.PLAIN, 25));
		authortextField.setBounds(307, 322, 127, 39);
		contentPane.add(authortextField);
		authortextField.setColumns(10);
		authortextField.setText(all_BookFrame.bookJtable.getValueAt(all_BookFrame.row, 3).toString());
		
		updateButton = new JButton(new ImageIcon("image/update.jpg"));
		updateButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				do_updateButton_UpdateBook(all_BookFrame);
			}
		});
		updateButton.setBounds(300, 602, 106, 37);
		contentPane.add(updateButton);
		
		JLabel background = new JLabel(new ImageIcon("image/updatebackground.jpg"));
		background.setBounds(0, 0, 602, 703);
		contentPane.add(background);
	}

	protected void do_updateButton_UpdateBook(Book_AllBook all_BookFrame) {
		BookTools bookTools = new BookTools();
		Book book = new Book();
		book.setIdBook(all_BookFrame.bookJtable.getValueAt(all_BookFrame.row, 0).toString());
		book.setType(all_BookFrame.bookJtable.getValueAt(all_BookFrame.row, 0).toString()=="在库"?false:true);
		if (nameBooktextField.getText() != null && !"".equals(nameBooktextField.getText()))
			book.setNameBook(nameBooktextField.getText());
		if(priceField.getText() != null && !"".equals(priceField.getText()))
			book.setPrice(new BigDecimal(priceField.getText()));
		if(authortextField.getText() != null && !"".equals(authortextField.getText()))
			book.setAuthor(authortextField.getText());
		int i = bookTools.UpdateBook(book);
		if (i == 1) {
	        JOptionPane.showMessageDialog(getContentPane(), "成功更新图书信息！", "", JOptionPane.WARNING_MESSAGE);
	        return;
		} else {
	        JOptionPane.showMessageDialog(getContentPane(), "更新图书信息失败！", "", JOptionPane.WARNING_MESSAGE);
	        return;
		}
	}
	
	public void CloseFrame(){
	    super.dispose();
	} 
}
