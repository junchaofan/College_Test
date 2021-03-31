package frame;

import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Iterator;
import java.util.List;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.border.EmptyBorder;
import javax.swing.table.DefaultTableModel;

import model.Book;
import sqlTools.BookTools;
import sqlTools.BorrowTools;
import sqlTools.ReturndealTools;

public class Book_Serach extends JFrame {

	/**
	 * Java的序列化机制是通过在运行时判断类的serialVersionUID来验证版本一致性的
	 */
	private static final long serialVersionUID = 1L;

	private JPanel contentPane;

	private JScrollPane bookScrollPane;
	public JTable bookJtable;
	private DefaultTableModel defaultModel;
	public static int row;

	private JLabel messageLabel;
	private JTextField nameBookField;
	private JButton searchButton;
	private JButton borrowButton;
	public Book_Serach() {
	 	setResizable(false);
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setBounds(100, 100, 996, 699);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);

		JButton borrow_Button = new JButton("重载");
		borrow_Button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Book_Serach search_BookFrame = new Book_Serach();
				search_BookFrame.setVisible(true);
				CloseFrame();
			}
		});
		borrow_Button.setBounds(77, 278, 123, 29);
		contentPane.add(borrow_Button);

		JButton self_info_Button = new JButton("还书");
		self_info_Button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Book_Return return_BookFrame = new Book_Return();
				return_BookFrame.setVisible(true);
				CloseFrame();
			}
		});
		self_info_Button.setBounds(77, 358, 123, 29);
		contentPane.add(self_info_Button);
		
		JButton moneyButton = new JButton("交款");
		moneyButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				JK_deal();
			}
		});
		moneyButton.setBounds(77, 438, 123, 29);
		contentPane.add(moneyButton);

		JButton log_out_Button = new JButton("登出");
		log_out_Button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Login loginframe = new Login();
				loginframe.setVisible(true);
				CloseFrame();
			}
		});
		log_out_Button.setBounds(77, 518, 123, 29);
		contentPane.add(log_out_Button);
		
		
		messageLabel = new JLabel("书名搜索");
		messageLabel.setFont(new Font("宋体", Font.PLAIN, 30));
		messageLabel.setBounds(539, 155, 123, 41);
		contentPane.add(messageLabel);

		nameBookField = new JTextField();
		nameBookField.setFont(new Font("宋体", Font.PLAIN, 30));
		nameBookField.setBounds(370, 209, 292, 37);
		contentPane.add(nameBookField);
		nameBookField.setColumns(10);

		searchButton = new JButton(new ImageIcon("image/search.jpg"));
		searchButton.setFont(new Font("宋体", Font.PLAIN, 30));
		searchButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				do_search_book();
			}
		});
		searchButton.setBounds(712, 209, 123, 41);
		contentPane.add(searchButton);

		bookScrollPane = new JScrollPane(bookJtable);
		bookScrollPane.setBounds(283, 261, 692, 323);
		contentPane.add(bookScrollPane);

		borrowButton = new JButton(new ImageIcon("image/borrow.jpg"));
		borrowButton.setFont(new Font("宋体", Font.PLAIN, 30));
		borrowButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				do_borrow_book();
			}
		});
		borrowButton.setBounds(539, 603, 123, 41);
		contentPane.add(borrowButton);
		// 显示全部图书信息
		show_data();

		JLabel background1 = new JLabel(new ImageIcon("image/background1.jpg"));
		background1.setBounds(0, 0, 990, 659);
		contentPane.add(background1);
	}

	private void JK_deal() {
		row = bookJtable.getSelectedRow();
		if (row == -1) {
			JOptionPane.showMessageDialog(this, "请在还书界面查询后操作", "", JOptionPane.WARNING_MESSAGE);
			return;
		}
		ReturndealTools newdeal=new ReturndealTools();
		if (newdeal.Deal_JK(bookJtable.getValueAt(row, 4).toString())==1) {
			JOptionPane.showMessageDialog(this, "交款成功", "", JOptionPane.WARNING_MESSAGE);
			return;
		} 
	}
	
	private void show_data() {

		bookJtable = new JTable();
		bookJtable.setAutoResizeMode(JTable.AUTO_RESIZE_SUBSEQUENT_COLUMNS);
		bookJtable.setRowHeight(30);

		defaultModel = (DefaultTableModel) bookJtable.getModel();
		defaultModel.setRowCount(0);
		defaultModel.setColumnIdentifiers(new Object[] { "编号", "书名", "单价", "作者", "是否在库" });

		bookJtable.getTableHeader().setReorderingAllowed(false);
		bookJtable.setModel(defaultModel);

		bookJtable.getColumnModel().getColumn(0).setPreferredWidth(20);
		bookJtable.getColumnModel().getColumn(1).setPreferredWidth(80);
		bookJtable.getColumnModel().getColumn(2).setPreferredWidth(20);
		bookJtable.getColumnModel().getColumn(3).setPreferredWidth(40);
		bookJtable.getColumnModel().getColumn(4).setPreferredWidth(20);

		BookTools bookTools = new BookTools();
		List<Book> booklist = bookTools.BookData();
		
		for (Iterator<Book> iterator = booklist.iterator(); iterator.hasNext();) {
			Book temp = (Book) iterator.next();
			String whetherInStock = null;

			if (!temp.getType()) {
				whetherInStock = "在库";
			} else {
				whetherInStock = "借出";
			}
			defaultModel.addRow(new Object[] { temp.getIdBook(), temp.getNameBook(), temp.getPrice(), temp.getAuthor(),  whetherInStock });
		}
		bookScrollPane.setViewportView(bookJtable);
	}

	private void do_search_book() {

		bookJtable = new JTable();
		bookJtable.setAutoResizeMode(JTable.AUTO_RESIZE_SUBSEQUENT_COLUMNS);
		bookJtable.setRowHeight(30);

		defaultModel = (DefaultTableModel) bookJtable.getModel();
		defaultModel.setRowCount(0);
		defaultModel.setColumnIdentifiers(new Object[] { "编号", "书名", "单价", "作者", "是否在库" });

		bookJtable.getTableHeader().setReorderingAllowed(false);
		bookJtable.setModel(defaultModel);

		bookJtable.getColumnModel().getColumn(0).setPreferredWidth(20);
		bookJtable.getColumnModel().getColumn(1).setPreferredWidth(80);
		bookJtable.getColumnModel().getColumn(2).setPreferredWidth(20);
		bookJtable.getColumnModel().getColumn(3).setPreferredWidth(40);
		bookJtable.getColumnModel().getColumn(4).setPreferredWidth(20);

		BookTools booktools = new BookTools();

		String keyword = null;
		if (nameBookField.getText() != null && !"".equals(nameBookField.getText())) {
			keyword = nameBookField.getText();
		} else {
			JOptionPane.showMessageDialog(this, "请输入书名", "", JOptionPane.WARNING_MESSAGE);
			return;
		}

		List<Book> booklist = booktools.BookData(keyword);

		if (booklist.size() == 0) {
			JOptionPane.showMessageDialog(this, "未找到有关书籍 ", "", JOptionPane.WARNING_MESSAGE);
			return;
		} else {
			for (Iterator<Book> iterator = booklist.iterator(); iterator.hasNext();) {
				Book temp = (Book) iterator.next();
				String whetherInStock = null;

				if (!temp.getType()) {
					whetherInStock = "在库";
				} else {
					whetherInStock = "借出";
				}
				defaultModel.addRow(new Object[] { temp.getIdBook(), temp.getNameBook(), temp.getPrice(), temp.getAuthor(),  whetherInStock });
			}
			bookScrollPane.setViewportView(bookJtable);
		}
	}

	private void do_borrow_book() {

		row = bookJtable.getSelectedRow();
		if (row == -1) {
			JOptionPane.showMessageDialog(this, "请选择书籍", "", JOptionPane.WARNING_MESSAGE);
			return;
		}
		if ("借出".equals(bookJtable.getValueAt(row, 4).toString())) {
			JOptionPane.showMessageDialog(this, "书籍已被借出", "", JOptionPane.WARNING_MESSAGE);
			return;
		} else {
			BorrowTools borrowtools = new BorrowTools();
			String idReader = Login.idReader;
			String idbook = bookJtable.getValueAt(row, 0).toString();
			int i = borrowtools.BorrowBook(idReader, idbook);
			if (i == 1) {
				JOptionPane.showMessageDialog(this, "借阅成功", "", JOptionPane.WARNING_MESSAGE);
				return;
			} else {
				JOptionPane.showMessageDialog(this, "借阅失败", "", JOptionPane.WARNING_MESSAGE);
				return;
			}
		}
	}

	public void CloseFrame() {
		super.dispose();
	}
}
