package sqlTools;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.List;

import database.DatabaseTools;
import model.ReturnBook;
import model.Book;
 
public class BorrowTools {
	
	//获取书本信息
	public List<ReturnBook> BookData(String idReader) {
		String sql="select T_TSXX.TSBH,TSMC,TSZZ,JYSJ,IFXJ from T_TSXX,T_JYXX where DZZH = ? and T_JYXX.TSBH=T_TSXX.TSBH";
		DatabaseTools db = new DatabaseTools();
		Connection conn = db.getConn();
		ResultSet rs=null;
		List<ReturnBook> ls=new ArrayList<ReturnBook>();
		try {
			PreparedStatement st =conn.prepareStatement(sql);
			st.setString(1, idReader);
			rs=st.executeQuery();
			while(rs.next()){
				ReturnBook book=new ReturnBook();
				book.setIdBook(rs.getString("T_TSXX.TSBH"));
				book.setNameBook(rs.getString("TSMC"));
				book.setAuthor(rs.getString("TSZZ"));
				book.setTime(rs.getString("JYSJ"));
				book.setType(rs.getBoolean("IFXJ"));
				ls.add(book);
			}
			rs.close();
			st.close();
			conn.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return ls;
	}
	
	//借书
	public int BorrowBook(String idReader,String idbook) {
		int i=0,count=0;
		String sql1="select MAX(JYDH) from T_JYXX";
		String sql2="insert into T_JYXX values(?,?,?,?,?)";
		String sql3="update T_TSXX set SFJC = true where TSBH = ?";
		DatabaseTools db = new DatabaseTools();
		Connection conn = db.getConn();
		try {
			PreparedStatement st = conn.prepareStatement(sql1);
			ResultSet rs = st.executeQuery();
			while(rs.next()) {
				count=rs.getInt("MAX(JYDH)")+1;
				st = conn.prepareStatement(sql2);
				st.setString(1, String.format("%06d",count));
				st.setString(2, idbook);
				st.setString(3, idReader);
				st.setString(4, new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(new java.util.Date()));
				st.setBoolean(5, false);
				st.executeUpdate();
				st = conn.prepareStatement(sql3);
				st.setString(1,idbook);
				i=st.executeUpdate();
			}
			st.close();
			conn.close();
		}catch (SQLException e) {
			e.printStackTrace();
		}
		return i;
	}
	
	//续借
	public int XJBook(String idbook) {
		int i=0;
		String sql1="update T_JYXX set IFXJ = ? where TSBH = ?";
		String sql2="update T_JYXX set JYSJ = ? where TSBH = ?";
		DatabaseTools db = new DatabaseTools();
		Connection conn = db.getConn();
		try {
			PreparedStatement st = conn.prepareStatement(sql1);
			st.setBoolean(1, true);
			st.setString(2, idbook);
			i=st.executeUpdate();
			st = conn.prepareStatement(sql2);
			st.setString(1, new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(new java.util.Date()));
			st.setString(2, idbook);
			i=st.executeUpdate();
			st.close();
			conn.close();
		}catch (SQLException e) {
			e.printStackTrace();
		}
		return i;
	}
	
	//还书
	public int ReturnBook(String idbook) {
		int i=0;
		String sql1="delete from T_JYXX where TSBH = ?";
		String sql2="update T_JYXX set JYDH = JYDH - 1 where JYDH > ?";
		String sql3="update T_TSXX set SFJC = false where TSBH = ?";
		
		DatabaseTools db = new DatabaseTools();
		Connection conn = db.getConn();
		try {
			PreparedStatement st = conn.prepareStatement(sql1);
			st.setString(1, idbook);
			i=st.executeUpdate();
			st = conn.prepareStatement(sql2);
			st.setString(1, return_JYDH(idbook));
			i=st.executeUpdate();
			st = conn.prepareStatement(sql3);
			st.setString(1, idbook);
			i=st.executeUpdate();
			st.close();
			conn.close();
		}catch (SQLException e) {
		e.printStackTrace();
		}
		return i;
	}
	
	//书籍是否为续借
	public boolean IFXJ_Book(String idReader,String idbook) {
		String sql="select IFXJ from T_JYXX where TSBH = ? and DZZH = ?";
		DatabaseTools db = new DatabaseTools();
		Connection conn = db.getConn();
		try {
			PreparedStatement st = conn.prepareStatement(sql);
			st.setString(2, idReader);
			st.setString(1, idbook);
			ResultSet rs = st.executeQuery();
			while(rs.next()) {
				return rs.getBoolean("JFXJ");
			}
			st.close();
			conn.close();
		}catch (SQLException e) {
		e.printStackTrace();
		}
		return false;
	}
	
	//返回以图书编号为搜索媒介的借阅单单号
	public String return_JYDH(String idbook) {
		String rt = null;
		String sql="select JYDH from T_JYXX where TSBH=?";
		DatabaseTools db = new DatabaseTools();
		Connection conn = db.getConn();
		try {
			PreparedStatement st = conn.prepareStatement(sql);
			st.setString(1, idbook);
			ResultSet rs = st.executeQuery();
			while(rs.next()) {
				rt=rs.getString("JYDH");
			}
			st.close();
			conn.close();
		}catch (SQLException e) {
		e.printStackTrace();
		}
		return rt;
	}
	
	//按照图书名称查找
	public List<Book> BookData_Search_nameBook(String nameBook) {
		String sql="select * from T_TSXX where TSMC = '" + nameBook + "'";
		DatabaseTools db = new DatabaseTools();
		Connection conn = db.getConn();
		ResultSet rs=null;
		List<Book> ls=new ArrayList<Book>();
		try {
			PreparedStatement st =conn.prepareStatement(sql);
			rs=st.executeQuery(sql);
			while(rs.next()){
				Book book=new Book();
				book.setIdBook(rs.getString("TSBH"));
				book.setNameBook(rs.getString("TSMC"));
				book.setPrice(rs.getBigDecimal("TSDJ"));
				book.setAuthor(rs.getString("TSZZ"));
				book.setType(rs.getBoolean("SFJC"));
				ls.add(book);
			}
			rs.close();
			st.close();
			conn.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return ls;
	}
	
	//按照图书编号查找
	public List<Book> BookData_Search_idBook(String idBook) {
		String sql="select * from T_TSXX where TSBH = '" + idBook + "'";
		DatabaseTools db = new DatabaseTools();
		Connection conn = db.getConn();
		ResultSet rs=null;
		List<Book> ls=new ArrayList<Book>();
		try {
			PreparedStatement st =conn.prepareStatement(sql);
			rs=st.executeQuery(sql);
			while(rs.next()){
				Book book=new Book();
				book.setIdBook(rs.getString("TSBH"));
				book.setNameBook(rs.getString("TSMC"));
				book.setPrice(rs.getBigDecimal("TSDJ"));
				book.setAuthor(rs.getString("TSZZ"));
				book.setType(rs.getBoolean("SFJC"));
				ls.add(book);
			}
			rs.close();
			st.close();
			conn.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return ls;
	}
	
	//判断书本是否在库
	public boolean whetherInStock(String idBook) {
		boolean judge=false;
		DatabaseTools db = new DatabaseTools();
		Connection conn = db.getConn();
		String sql = "select * from T_TSXX where TSBH = ?";
		try {
			PreparedStatement st =conn.prepareStatement(sql);
			st.setString(1, idBook);
			ResultSet rs = st.executeQuery();
			while (rs.next()) {
				judge=rs.getBoolean("SFJC");
			}
			st.close();
			conn.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return judge;
	}
}
