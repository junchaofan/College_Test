package model;

public class ReturnBook {
	private String idBook;
	private String nameBook;
	private String ttime;
	private boolean type;
	private String author;
	public String getIdBook() {
		return idBook;
	}
	public void setIdBook(String idBook) {
		this.idBook = idBook;
	}
	public String getNameBook() {
		return nameBook;
	}
	public void setNameBook(String nameBook) {
		this.nameBook = nameBook;
	}
	public String getAuthor() {
		return author;
	}
	public void setAuthor(String author) {
		this.author = author;
	}
	public String getTime() {
		return ttime;
	}
	public void setTime(String ttime) {
		this.ttime = ttime;
	}
	public boolean getType() {
		return type;
	}
	public void setType(boolean type) {
		this.type = type;
	}
	

	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((idBook == null) ? 0 : idBook.hashCode());
		return result;
	}

	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		ReturnBook other = (ReturnBook) obj;
		if (author == null) {
			if (other.author != null)
				return false;
		} else if (!author.equals(other.author))
			return false;
		if (idBook == null) {
			if (other.idBook != null)
				return false;
		} else if (!idBook.equals(other.idBook))
			return false;
		if (nameBook == null) {
			if (other.nameBook != null)
				return false;
		} else if (!nameBook.equals(other.nameBook))
			return false;
		if (ttime == null) {
			if (other.ttime != null)
				return false;
		} else if (!ttime.equals(other.ttime))
			return false;
		return true;
	}

	public String toString() {
		return "ReturnBook [idBook=" + idBook + ", nameBook=" + nameBook   + ", author="
				+ author + ", ttime=" + ttime + ", type=" + type + "]";
	}

}
