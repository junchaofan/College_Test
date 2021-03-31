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
import javax.swing.JLayeredPane;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.border.EmptyBorder;
import javax.swing.table.DefaultTableModel;

import model.ReturnBook;
import sqlTools.BorrowTools;
import sqlTools.ReaderTools;

public class Book_Return extends JFrame {

	/**
	 * Java的序列化机制是通过在运行时判断类的serialVersionUID来验证版本一致性的
	 */
	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JLayeredPane layeredPane;

	private JScrollPane bookScrollPane;
	private JTable bookJtable;
	private DefaultTableModel defaultModel;
	public static int row;

	private JLabel idReaderLabel;
	private JLabel nameReaderLabel;
	private JLabel typeLabel;
	private JLabel showidReaderLabel;

	private JLabel showNameReaderLabel;
	private JLabel showTypeLabel;
	private JButton return_BookButton;

	public Book_Return() {
		ReaderTools localreader = new ReaderTools();
		if (localreader.IFFK(Login.idReader)) {
	        JOptionPane.showMessageDialog(getContentPane(), "罚款未交,还书失败", "", JOptionPane.WARNING_MESSAGE);
	        return;
		}
		setResizable(false);
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setBounds(100, 100, 996, 699);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JButton reload_Button = new JButton("返回");
		reload_Button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Book_Serach search_BookFrame = new Book_Serach();
				search_BookFrame.setVisible(true);
				CloseFrame();
			}
		});
		reload_Button.setBounds(77, 278, 123, 29);
		contentPane.add(reload_Button);

		JButton borrow_Button = new JButton("续借");
		borrow_Button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				do_borrow_book();
			}
		});
		borrow_Button.setBounds(77, 358, 123, 29);
		contentPane.add(borrow_Button);

		JButton self_info_Button = new JButton("还书");
		self_info_Button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				do_return_book();
			}
		});
		self_info_Button.setBounds(77, 438, 123, 29);
		contentPane.add(self_info_Button);

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

		layeredPane = new JLayeredPane();
		layeredPane.setBounds(128, 61, 862, 598);
		contentPane.add(layeredPane);

		idReaderLabel = new JLabel("借阅证号");
		idReaderLabel.setFont(new Font("宋体", Font.PLAIN, 30));
		idReaderLabel.setBounds(311, 102, 158, 43);
		layeredPane.add(idReaderLabel);

		nameReaderLabel = new JLabel("姓名");
		nameReaderLabel.setFont(new Font("宋体", Font.PLAIN, 30));
		nameReaderLabel.setBounds(241, 171, 81, 32);
		layeredPane.add(nameReaderLabel);

		typeLabel = new JLabel("电话");
		typeLabel.setFont(new Font("宋体", Font.PLAIN, 30));
		typeLabel.setBounds(507, 171, 158, 32);
		layeredPane.add(typeLabel);

		showidReaderLabel = new JLabel();
		showidReaderLabel.setFont(new Font("宋体", Font.PLAIN, 30));
		showidReaderLabel.setBounds(491, 102, 146, 43);
		layeredPane.add(showidReaderLabel);
		showidReaderLabel.setText(Login.idReader);

		showNameReaderLabel = new JLabel("");
		showNameReaderLabel.setFont(new Font("宋体", Font.PLAIN, 30));
		showNameReaderLabel.setBounds(348, 171, 144, 32);
		layeredPane.add(showNameReaderLabel);
		showNameReaderLabel.setText(localreader.return_DZMC(Login.idReader));

		showTypeLabel = new JLabel("");
		showTypeLabel.setFont(new Font("宋体", Font.PLAIN, 30));
		showTypeLabel.setBounds(604, 170, 197, 33);
		layeredPane.add(showTypeLabel);
		showTypeLabel.setText(localreader.return_DZDH(Login.idReader));
		
		bookScrollPane = new JScrollPane(bookJtable);
		bookScrollPane.setBounds(197, 271, 576, 249);
		layeredPane.add(bookScrollPane);

		return_BookButton = new JButton(new ImageIcon("image/update.jpg"));
		return_BookButton.setBounds(401, 540, 123, 43);
		return_BookButton.setFont(new Font("宋体", Font.PLAIN, 30));
		return_BookButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Book_Return return_BookFrame = new Book_Return();
				return_BookFrame.setVisible(true);
				CloseFrame();
			}
		});
		layeredPane.add(return_BookButton);

		show_data();

		JLabel background1 = new JLabel(new ImageIcon("image/background1.jpg"));
		background1.setBounds(0, 0, 990, 659);
		contentPane.add(background1);
	}

	private void show_data() {

		bookJtable = new JTable();
		bookJtable.setAutoResizeMode(JTable.AUTO_RESIZE_SUBSEQUENT_COLUMNS);
		bookJtable.setRowHeight(30);

		defaultModel = (DefaultTableModel) bookJtable.getModel();
		defaultModel.setRowCount(0);
		defaultModel.setColumnIdentifiers(new Object[] { "图书编号", "书名", "作者", "借阅时间", "可否续借" });

		bookJtable.getTableHeader().setReorderingAllowed(false);
		bookJtable.setModel(defaultModel);

		bookJtable.getColumnModel().getColumn(0).setPreferredWidth(20);
		bookJtable.getColumnModel().getColumn(1).setPreferredWidth(80);
		bookJtable.getColumnModel().getColumn(2).setPreferredWidth(80);
		bookJtable.getColumnModel().getColumn(3).setPreferredWidth(80);
		bookJtable.getColumnModel().getColumn(4).setPreferredWidth(20);

		BorrowTools borrowtools = new BorrowTools();
		List<ReturnBook> borrowlist = borrowtools.BookData(Login.idReader);
		
		for (Iterator<ReturnBook> iterator = borrowlist.iterator(); iterator.hasNext();) {
			ReturnBook temp = (ReturnBook) iterator.next();
			String whetherInStock = null;
			if (!temp.getType()) {
				whetherInStock = "批准";
			} else {
				whetherInStock = "拒绝";
			}
			defaultModel.addRow(new Object[] { temp.getIdBook(), temp.getNameBook(), temp.getAuthor(), temp.getTime(),  whetherInStock });
		}
		bookScrollPane.setViewportView(bookJtable);
	}

	private void do_borrow_book() {
		row = bookJtable.getSelectedRow();
		if (row == -1) {
			JOptionPane.showMessageDialog(this, "请选择书籍", "", JOptionPane.WARNING_MESSAGE);
			return;
		}
		BorrowTools borrowtools = new BorrowTools();
		String idbook = bookJtable.getValueAt(row, 0).toString();
		if (bookJtable.getValueAt(row, 4).toString()=="拒绝") {
			JOptionPane.showMessageDialog(this, "该书已被续借,借书失败", "", JOptionPane.WARNING_MESSAGE);
			return;
		}
		int i = borrowtools.XJBook(idbook);
		if (i == 1) {
			JOptionPane.showMessageDialog(this, "续借成功", "", JOptionPane.WARNING_MESSAGE);
			show_data();
			return;
		} else {
			JOptionPane.showMessageDialog(this, "续借失败", "", JOptionPane.WARNING_MESSAGE);
			show_data();
			return;
		}
	}
	
	private void do_return_book() {
		row = bookJtable.getSelectedRow();
		if (row == -1) {
			JOptionPane.showMessageDialog(this, "请选择书籍", "", JOptionPane.WARNING_MESSAGE);
			return;
		}
		BorrowTools borrowtools = new BorrowTools();
		String idbook = bookJtable.getValueAt(row, 0).toString();
		int i = borrowtools.ReturnBook(idbook);
		if (i == 1) {
			JOptionPane.showMessageDialog(this, "还书成功", "", JOptionPane.WARNING_MESSAGE);
			show_data();
			return;
		} else {
			JOptionPane.showMessageDialog(this, "还书失败", "", JOptionPane.WARNING_MESSAGE);
			show_data();
			return;
		}
	}

	public void CloseFrame() {
		super.dispose();
	}
}

//if(borrowtools.IFXJ_Book(idReader,idbook)) {
//	JOptionPane.showMessageDialog(this, "续借失败，该书已被您续借一次", "", JOptionPane.WARNING_MESSAGE);
//	return;
//}
