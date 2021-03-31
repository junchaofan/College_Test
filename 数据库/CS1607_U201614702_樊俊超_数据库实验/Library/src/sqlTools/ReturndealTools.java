package sqlTools;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import database.DatabaseTools;
import model.Returndeal;

public class ReturndealTools {
	//获取还书申请
		public List<Returndeal> DealBookData(String idReader) {
			String sql="select HSDH,T_HSXX.JYDH,JYSJ,HSSJ,TSZT,IFFK,IFSH from T_HSXX,T_JYXX where DZZH = ?";
			DatabaseTools db = new DatabaseTools();
			Connection conn = db.getConn();
			ResultSet rs=null;
			List<Returndeal> ls=new ArrayList<Returndeal>();
			try {
				PreparedStatement st =conn.prepareStatement(sql);
				st.setString(1, idReader);
				rs=st.executeQuery();
				while(rs.next()){
					Returndeal book=new Returndeal();
					book.setIdReturnBook(rs.getString("HSDH"));
					book.setIdJYBook(rs.getString("T_HSXX.JYDH"));
					book.setJYtime(rs.getString("JYSJ"));
					book.setHStime(rs.getString("HSSJ"));
					book.setSHtype(rs.getBoolean("TSZT"));
					book.setFKtype(rs.getBoolean("IFFK"));
					book.setSHtype(rs.getBoolean("IFSH"));
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
		
		//获取还书申请
			public List<Returndeal> DealBookData() {
				String sql="select HSDH,T_HSXX.JYDH,JYSJ,HSSJ,TSZT,IFFK,IFSH from T_HSXX,T_JYXX";
				DatabaseTools db = new DatabaseTools();
				Connection conn = db.getConn();
				ResultSet rs=null;
				List<Returndeal> ls=new ArrayList<Returndeal>();
				try {
					PreparedStatement st =conn.prepareStatement(sql);
					rs=st.executeQuery();
					while(rs.next()){
						Returndeal book=new Returndeal();
						book.setIdReturnBook(rs.getString("HSDH"));
						book.setIdJYBook(rs.getString("T_HSXX.JYDH"));
						book.setJYtime(rs.getString("JYSJ"));
						book.setHStime(rs.getString("HSSJ"));
						book.setSHtype(rs.getBoolean("TSZT"));
						book.setFKtype(rs.getBoolean("IFFK"));
						book.setSHtype(rs.getBoolean("IFSH"));
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
			
			//更新还书申请单图书状态
			public int UpdatedealTS(String idReturnbook) {
				int i=0;
				String sql1="select TSZT from T_HSXX where HSDH=?";
				String sql2="update T_HSXX set TSZT = ? where HSDH = ?";
				String sql3="update T_HSXX set IFFK = ? where HSDH = ?";
				DatabaseTools db = new DatabaseTools();
				Connection conn = db.getConn();
				try {
					PreparedStatement st = conn.prepareStatement(sql1);
					st.setString(1, idReturnbook);
					ResultSet rs=st.executeQuery();
					while(rs.next()) {
						boolean ZT=!rs.getBoolean("TSZT");
						st = conn.prepareStatement(sql2);
						st.setString(2, idReturnbook);
						st.setBoolean(1, ZT);
						i=st.executeUpdate();
						if(ZT) {
							st = conn.prepareStatement(sql3);
							st.setString(2, idReturnbook);
							st.setBoolean(1, true);
							i=st.executeUpdate();
						}
					}
					st.close();
					conn.close();
				}catch (SQLException e) {
				e.printStackTrace();
				}
				return i;
			}
			
			//书籍是否已审核
			public boolean IFSH_Book(String idReturnbook) {
				String sql="select IFSH from T_HSXX where HSDH = ?";
				DatabaseTools db = new DatabaseTools();
				Connection conn = db.getConn();
				try {
					PreparedStatement st = conn.prepareStatement(sql);
					st.setString(1, idReturnbook);
					ResultSet rs = st.executeQuery();
					while(rs.next()) {
						return rs.getBoolean("IFSH");
					}
					st.close();
					conn.close();
				}catch (SQLException e) {
				e.printStackTrace();
				}
				return false;
			}
			
			//更新还书申请单审核状态
			public int UpdatedealSH(String idReturnbook) {
				int i=0;
				String sql1="select IFSH from T_HSXX where HSDH=?";
				String sql2="update T_HSXX set IFSH = ? where HSDH = ?";
				DatabaseTools db = new DatabaseTools();
				Connection conn = db.getConn();
				try {
					PreparedStatement st = conn.prepareStatement(sql1);
					st.setString(1, idReturnbook);
					ResultSet rs=st.executeQuery();
					while(rs.next()) {
						boolean ZT=!rs.getBoolean("IFSH");
						st = conn.prepareStatement(sql2);
						st.setString(2, idReturnbook);
						st.setBoolean(1, ZT);
						i=st.executeUpdate();
					}
					st.close();
					conn.close();
				}catch (SQLException e) {
				e.printStackTrace();
				}
				return i;
			}
			
			//更新还书申请单罚款状态
			public int UpdatedealFK(String idReturnbook) {
				String sql="update T_HSXX set IFFK = true where HSDH = ?";
				DatabaseTools db = new DatabaseTools();
				Connection conn = db.getConn();
				try {
					PreparedStatement st = conn.prepareStatement(sql);
					st.setString(1, idReturnbook);
					st.executeUpdate();
					st.close();
					conn.close();
				}catch (SQLException e) {
				e.printStackTrace();
				}
				return this.UpdatedealSH(idReturnbook);
			}
			
			public int Deal_JK(String idJYDH) {
				int i=0;
				String sql1="update T_HSXX seet IFSH=true where JYDH=?";
				DatabaseTools db = new DatabaseTools();
				Connection conn = db.getConn();
				try {
					PreparedStatement st = conn.prepareStatement(sql1);
					st.setString(1, idJYDH);		
					i=st.executeUpdate();
					st.close();
					conn.close();
				}catch (SQLException e) {
				e.printStackTrace();
				}
				return i;
			}
}			

