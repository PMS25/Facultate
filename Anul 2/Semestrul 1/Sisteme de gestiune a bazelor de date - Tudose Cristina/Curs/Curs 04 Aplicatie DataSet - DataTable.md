# Curs04 Aplicatie DataSet - DataTable

```c#
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;

namespace Data_table
{
    class Std
    {
        DataSet ds;
        DataTable dtStd;
        DataTable dtSpec;
        public Std()
        {
            dtSpec = new DataTable("wSpecializari");
            dtSpec.Columns.Add("CodSpecializare", Type.GetType("System.String"));
            dtSpec.Columns.Add("Denumire", Type.GetType("System.String"));
   
            DataColumn[] pk = new DataColumn[1];
            pk[0] = dtSpec.Columns["CodSpecializare"];
            dtSpec.PrimaryKey = pk;

            dtStd = new DataTable("wStudenti");
            dtStd.Columns.Add("ID",Type.GetType("System.Int16"));
            dtStd.Columns.Add("CodSpecializare",Type.GetType("System.String"));
            dtStd.Columns.Add("Nume", Type.GetType("System.String"));
            dtStd.Columns.Add("Media", Type.GetType("System.Decimal"));
            UniqueConstraint uk = new UniqueConstraint(dtStd.Columns["Nume"]);
            dtStd.Columns["id"].AutoIncrement = true;
            
            pk = new DataColumn[1];
            pk[0] = dtStd.Columns["ID"];
            dtStd.PrimaryKey = pk;

            ForeignKeyConstraint fk = new ForeignKeyConstraint("FK_Spec", dtSpec.Columns["CodSpecializare"], dtStd.Columns["CodSpecializare"]);

            ds = new DataSet();
            ds.Tables.Add(dtSpec);
            ds.Tables.Add(dtStd);
        }

        public void SpecRandNou(string codSpecializare, string denumire)
        {
            DataRow dr = dtSpec.NewRow();
            dr["CodSpecializare"] = codSpecializare;
            dr["Denumire"] = denumire;
            dtSpec.Rows.Add(dr);
        }

        public void StdRandNou(string codSpecializare,string nume, decimal media)
        {
            DataRow dr = dtStd.NewRow();
            dr["CodSpecializare"] = codSpecializare;
            dr["nume"] = nume;
            dr["media"] = media;
            dtStd.Rows.Add(dr);
        }

        public void ListareStd()
        {
            foreach (DataRow dr in dtStd.Rows)
                Console.WriteLine("{0} {1} {2} {3}", dr["ID"], dr["CodSpecializare"], dr["Nume"], dr["Media"]);
        }

        public void UtilizareRelatie()
        {
            DataRelation rel = new DataRelation("Spec_Std", dtSpec.Columns["CodSpecializare"],
                dtStd.Columns["CodSpecializare"]);
            ds.Relations.Add(rel);
             foreach(DataRow specializare in dtSpec.Rows)
             {
                 Console.WriteLine(specializare["denumire"].ToString());
                 foreach (DataRow stud in specializare.GetChildRows(rel))
                    Console.WriteLine(specializare["denumire"].ToString() +" "+ stud["Nume"]);

             }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {

            Std s = new Std();
            s.SpecRandNou("Mate", "Matematica");
            s.SpecRandNou("Info", "Informatica");
            s.StdRandNou("Mate","Ana", 9);
            s.StdRandNou("Mate","Ionel", 8);
            s.StdRandNou("Info","Dragos", 10);

            s.ListareStd();

            s.UtilizareRelatie();
            Console.ReadKey();


        }
    }
}
```

