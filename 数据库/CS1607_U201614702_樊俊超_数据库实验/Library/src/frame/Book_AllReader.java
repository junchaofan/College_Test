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
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.border.EmptyBorder;
import javax.swing.table.DefaultTableModel;

import model.Reader;
import sqlTools.ReaderTools;

public class Book_AllReader extends JFrame {

	/**
	 * Java的序列化机制是通过在运行时判断类的serialVersionUID来验证版本一致性的
	 */
	private static final long serialVersionUID = 1L;
	private JPanel contentPane;

	private JScrollPane readerScrollPane;
	public JTable readerJtable;
	private DefaultTableModel defaultModel;
	public int row;
	private JButton updateButton;
	private JButton deleteButton;

	public Book_AllReader() {
		setResizable(false);
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setBounds(100, 100, 996, 699);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel NameLabel = new JLabel("读者管理");
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

		readerScrollPane = new JScrollPane();
		readerScrollPane.setBounds(302, 197, 611, 381);
		contentPane.add(readerScrollPane);

		updateButton = new JButton(new ImageIcon("image/update.jpg"));
		updateButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				update_Reader();
			}
		});
		updateButton.setBounds(417, 604, 123, 40);
		contentPane.add(updateButton);

		deleteButton = new JButton(new ImageIcon("image/delete.jpg"));
		deleteButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				delete_data();
			}
		});
		deleteButton.setBounds(628, 604, 123, 40);
		contentPane.add(deleteButton);

		show_data();

		JLabel background1 = new JLabel(new ImageIcon("image/background1.jpg"));
		background1.setBounds(0, 0, 990, 659);
		contentPane.add(background1);
	}

	//显示所有信息
	private void show_data() {

		readerJtable = new JTable();
		readerJtable.setAutoResizeMode(JTable.AUTO_RESIZE_SUBSEQUENT_COLUMNS);
		readerJtable.setRowHeight(30);

		defaultModel = (DefaultTableModel) readerJtable.getModel();
		defaultModel.setRowCount(0);
		defaultModel.setColumnIdentifiers(new Object[] { "读者账号", "姓名", "电话", "密码" });

		readerJtable.getTableHeader().setReorderingAllowed(false);
		readerJtable.setModel(defaultModel);

		readerJtable.getColumnModel().getColumn(0).setPreferredWidth(20);
		readerJtable.getColumnModel().getColumn(1).setPreferredWidth(40);
		readerJtable.getColumnModel().getColumn(2).setPreferredWidth(80);
		readerJtable.getColumnModel().getColumn(3).setPreferredWidth(20);

		ReaderTools readerTools = new ReaderTools();
		List<Reader> readerlist = readerTools.ReaderData();

		for (Iterator<Reader> iterator = readerlist.iterator(); iterator.hasNext();) {
			Reader temp = (Reader) iterator.next();
			defaultModel.addRow(new Object[] { temp.getIdReader(), temp.getNameReader(), temp.getType(), temp.getPassword()});
		}
		readerScrollPane.setViewportView(readerJtable);
	}

	private void update_Reader() {
		row = readerJtable.getSelectedRow();
		if (row == -1) {
			JOptionPane.showMessageDialog(this, "请选择读者！", "", JOptionPane.WARNING_MESSAGE);
			return;
		}
		Reader idReader=new Reader();
		idReader.setIdReader(readerJtable.getValueAt(row, 0).toString());
		new ReaderTools().setNewreader(idReader);
		Reader_Update reader_UpdateFrame = new Reader_Update(Book_AllReader.this);
		reader_UpdateFrame.setVisible(true);
	}

	private void delete_data() {
		int row = readerJtable.getSelectedRow();
		if (row == -1) {
			JOptionPane.showMessageDialog(this, "请选择读者", "", JOptionPane.WARNING_MESSAGE);
			return;
		}
		ReaderTools readerTools = new ReaderTools();
		if(readerTools.IF_borrow(readerJtable.getValueAt(row, 0).toString())) {
			JOptionPane.showMessageDialog(getContentPane(), "删除读者信息失败，该读者尚有书籍未归还", "", JOptionPane.WARNING_MESSAGE);
			return;
		}
		int i = readerTools.DeleteReader(readerJtable.getValueAt(row, 0).toString());
		if (i == 1) {
			JOptionPane.showMessageDialog(getContentPane(), "成功删除读者信息！", "", JOptionPane.WARNING_MESSAGE);
			this.show_data();
			return;
		} else {
			JOptionPane.showMessageDialog(getContentPane(), "删除读者信息失败！", "", JOptionPane.WARNING_MESSAGE);
			return;
		}
	}

	public void CloseFrame() {
		super.dispose();
	}
}
