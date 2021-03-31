package frame;

import java.awt.Color;
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
import javax.swing.JTextField;
import javax.swing.border.EmptyBorder;
import javax.swing.table.DefaultTableModel;

import model.Reader;
import model.Returndeal;
import sqlTools.ReaderTools;
import sqlTools.ReturndealTools;

public class CheckReaderFrame extends JFrame {

	/**
	 * Java的序列化机制是通过在运行时判断类的serialVersionUID来验证版本一致性的
	 */
	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JLayeredPane layeredPane;

	private JScrollPane bookScrollPane;
	private JTable bookJtable;
	private DefaultTableModel defaultModel;

	private JLabel idReaderLabel;
	private JLabel nameReaderLabel;
	private JLabel typeLabel;
	private JTextField idReadertextField;

	private JLabel showNameReaderLabel;
	private JLabel showTypeLabel;
	public int row;
	
	public CheckReaderFrame() {
		setResizable(false);
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setBounds(100, 100, 996, 699);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel NameLabel = new JLabel("还书申请");
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
		typeLabel.setBounds(507, 171, 200, 32);
		layeredPane.add(typeLabel);

		idReadertextField = new JTextField();
		idReadertextField.setFont(new Font("宋体", Font.PLAIN, 30));
		idReadertextField.setBounds(491, 102, 146, 43);
		idReadertextField.setColumns(10);
		layeredPane.add(idReadertextField);

		showNameReaderLabel = new JLabel("");
		showNameReaderLabel.setFont(new Font("宋体", Font.PLAIN, 30));
		showNameReaderLabel.setBounds(348, 171, 144, 32);
		layeredPane.add(showNameReaderLabel);

		showTypeLabel = new JLabel("");
		showTypeLabel.setFont(new Font("宋体", Font.PLAIN, 30));
		showTypeLabel.setBounds(604, 170, 200, 33);
		layeredPane.add(showTypeLabel);
		
		JButton TSTypeChangeButton = new JButton("图书状态更改");
		TSTypeChangeButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				book_update_TSType();
			}
		});
		TSTypeChangeButton.setBounds(360, 280, 130, 30);
		contentPane.add(TSTypeChangeButton);
		
		JButton SHTypeChangeButton = new JButton("审核状态更改");
		SHTypeChangeButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				book_update_SHType();
			}
		});
		SHTypeChangeButton.setBounds(670, 280, 130, 30);
		contentPane.add(SHTypeChangeButton);
		
		JButton FKTypeChangeButton = new JButton("罚款状态更改");
		FKTypeChangeButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				book_update_FKType();
			}
		});
		FKTypeChangeButton.setBounds(520, 280, 130, 30);
		contentPane.add(FKTypeChangeButton);
		
		JButton btnNewButton = new JButton(new ImageIcon("image/query.jpg"));
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				show_data();
			}
		});
		btnNewButton.setBounds(401, 540, 105, 43);
		layeredPane.add(btnNewButton);

		bookScrollPane = new JScrollPane(bookJtable);
		bookScrollPane.setBounds(197, 271, 576, 260);
		layeredPane.add(bookScrollPane);

		JLabel background1 = new JLabel(new ImageIcon("image/background1.jpg"));
		background1.setBounds(0, 0, 990, 659);
		contentPane.add(background1);

	}
	
	//更新图书状态
	private void book_update_TSType() {
		row = bookJtable.getSelectedRow();
		if (row == -1) {
			JOptionPane.showMessageDialog(this, "请选择还书申请单", "", JOptionPane.WARNING_MESSAGE);
			return;
		}
		ReturndealTools dealtools = new ReturndealTools();
		if(dealtools.IFSH_Book(bookJtable.getValueAt(row, 0).toString())) {
			JOptionPane.showMessageDialog(this, "还书申请已审核", "", JOptionPane.WARNING_MESSAGE);
			return;
		}
		dealtools.UpdatedealTS(bookJtable.getValueAt(row, 0).toString());
		show_data();
	}
	
	//更新罚款状态
		private void book_update_SHType() {
			row = bookJtable.getSelectedRow();
			if (row == -1) {
				JOptionPane.showMessageDialog(this, "请选择还书申请单", "", JOptionPane.WARNING_MESSAGE);
				return;
			}
			ReturndealTools dealtools = new ReturndealTools();
			if(dealtools.IFSH_Book(bookJtable.getValueAt(row, 0).toString())) {
				JOptionPane.showMessageDialog(this, "审核信息已更改", "", JOptionPane.WARNING_MESSAGE);
				return;
			}
			dealtools.UpdatedealSH(bookJtable.getValueAt(row, 0).toString());
			show_data();
		}
	
	//更新罚款状态
		private void book_update_FKType() {
			row = bookJtable.getSelectedRow();
			if (row == -1) {
				JOptionPane.showMessageDialog(this, "请选择还书申请单", "", JOptionPane.WARNING_MESSAGE);
				return;
			}
			ReturndealTools dealtools = new ReturndealTools();
			if(dealtools.IFSH_Book(bookJtable.getValueAt(row, 0).toString())) {
				JOptionPane.showMessageDialog(this, "已更改", "", JOptionPane.WARNING_MESSAGE);
				return;
			}
			dealtools.UpdatedealFK(bookJtable.getValueAt(row, 0).toString());
			show_data();
		}
	
	//显示信息
	private void show_data() {
		bookJtable = new JTable();
		bookJtable.setAutoResizeMode(JTable.AUTO_RESIZE_SUBSEQUENT_COLUMNS);
		bookJtable.setRowHeight(30);

		defaultModel = (DefaultTableModel) bookJtable.getModel();
		defaultModel.setRowCount(0);
		defaultModel.setColumnIdentifiers(new Object[] { "还书单号", "借阅单号", "借阅时间", "还书时间", "图书状态","是否罚款","是否批准"});

		bookJtable.getTableHeader().setReorderingAllowed(false);
		bookJtable.setModel(defaultModel);

		bookJtable.getColumnModel().getColumn(0).setPreferredWidth(20);
		bookJtable.getColumnModel().getColumn(1).setPreferredWidth(20);
		bookJtable.getColumnModel().getColumn(2).setPreferredWidth(80);
		bookJtable.getColumnModel().getColumn(3).setPreferredWidth(80);
		bookJtable.getColumnModel().getColumn(4).setPreferredWidth(20);
		bookJtable.getColumnModel().getColumn(5).setPreferredWidth(20);
		bookJtable.getColumnModel().getColumn(6).setPreferredWidth(20);
		ReaderTools readerTools = new ReaderTools();
		Reader reader = new Reader();
		ReturndealTools dealtools = new ReturndealTools();
		List<Reader> readerlist;
		List<Returndeal> deallist;
		if (idReadertextField.getText() != null && !"".equals(idReadertextField.getText())) {
			reader.setIdReader(idReadertextField.getText());
			readerlist = readerTools.ReaderData(reader.getIdReader());
			deallist = dealtools.DealBookData(reader.getIdReader());
		} else {
			JOptionPane.showMessageDialog(this, "默认全部还书申请信息", "", JOptionPane.WARNING_MESSAGE);
			readerlist = readerTools.ReaderData();
			deallist = dealtools.DealBookData();
		}
		if (readerlist.size() == 0) {
			JOptionPane.showMessageDialog(this, "读者编号错误，请输入正确的读者编号 ", "", JOptionPane.WARNING_MESSAGE);
			return;
		} else {
			for (Iterator<Reader> iterator = readerlist.iterator(); iterator.hasNext();) {
				Reader temp = (Reader) iterator.next();
				showNameReaderLabel.setText(temp.getNameReader());
				showTypeLabel.setText(temp.getType());
			}
			for (Iterator<Returndeal> iterator = deallist.iterator(); iterator.hasNext();) {
				Returndeal temp = (Returndeal) iterator.next();
				defaultModel.addRow(new Object[] { temp.getIdReturnBook(),temp.getIdJYBook(),temp.getJYtime(),temp.getHStime(),
					temp.isTStype() ? "破损":"无损",temp.isFKtype() ? "是":"否",temp.isSHtype() ? "已审":"待审"});
			}
		}
		bookScrollPane.setViewportView(bookJtable);
	}

	public void CloseFrame() {
		super.dispose();
	}
}
