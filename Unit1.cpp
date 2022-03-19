//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "mySQLDbTables"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

bool __fastcall TForm1::FillGrid(TObject *Sender, String strSQL)
{

  MySQLQuery1->Active=false;
  MySQLQuery1->SQL->Clear();
  MySQLQuery1->SQL->Add(strSQL);
  MySQLQuery1->Active=true;

  StringGrid1->Cells[0][0]="#";
  StringGrid1->Cells[1][0]="text";
  StringGrid1->Cells[2][0]="description";
  StringGrid1->Cells[3][0]="keywords";

  int nRow=1;
  while (!MySQLQuery1->Eof) {
	StringGrid1->RowCount=nRow+1;
	StringGrid1->ColCount=MySQLQuery1->FieldCount;

	for (int nCol=0; nCol< MySQLQuery1->FieldCount; nCol++) {
	  StringGrid1->Cells[nCol][nRow]=MySQLQuery1->Fields[0][nCol]->AsString;
	}

	MySQLQuery1->Next();
	nRow++;
  }
  return true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	String strSQL = "SELECT * FROM myarttable ORDER BY id DESC;";
	FillGrid (Sender, strSQL);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
  Memo1->Text = "INSERT INTO myarttable SET text='"+Edit1->Text+"', description='"+Edit2->Text+"', keywords='"+Edit3->Text+"';";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
  Memo1->Text = "UPDATE myarttable SET keywords = 'Ivanov' WHERE id = 18;";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
  Memo1->Text = "DELETE FROM myarttable WHERE id<14;";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
  MySQLQuery1->SQL->Text = Memo1->Text;
  MySQLQuery1->ExecSQL();
  Button1->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
  Memo1->Text = "CREATE DATABASE IF NOT EXISTS test; USE test; CREATE TABLE IF NOT EXISTS myArtTable (id int(11) NOT NULL auto_increment, text text NOT NULL, description text NOT NULL, keywords text NOT NULL, PRIMARY KEY (id)) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=cp1251; CREATE TABLE IF NOT EXISTS files (id_file int(11) NOT NULL auto_increment, id_my int(11) NOT NULL, description text NOT NULL, name_origin text NOT NULL, path text NOT NULL, date_upload text NOT NULL, PRIMARY KEY (id_file), FOREIGN KEY (id_my) REFERENCES myarttable(id)) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=cp1251; INSERT INTO myarttable (text, description, keywords) values ('new text1', 'new desc2', 'key3');";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	String strSQL = "SELECT * FROM myarttable ORDER BY id ASC;";
	FillGrid (Sender, strSQL);
}
//---------------------------------------------------------------------------

