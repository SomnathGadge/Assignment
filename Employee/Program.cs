using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Employee
{
    public enum Dept
    {
            IT,
            HR,
            Payroll,
            Engineering,
            Admin,
            Sales
    }
    public enum Gender
    {
            Male,
            Female,
            Unknown
    }
    public enum Country
    {
            India,
            Japan,
            Australia,
            US
    }
    class Emp
    {
        
        public int ID
        {
            set; get;
        }
        public string First_Name
        {
            set;
            get;
        }
        public string Last_Name
        {
            set;
            get;
        }
        public int Salary
        {
            set;
            get;
        }
        public Dept Department
        {
            set;
            get;
        }
        public Country Country1
        {
            set;
            get;
        }
        public Gender gender
        {
            set;
            get;
        }
    }
    class Database
    {
        List<Emp> employeeList=new List<Emp>();
        int n;
        public void Accept_Employee()
        {
            try
            {
                Console.WriteLine("Enter How many Employee:");
                n = Convert.ToInt32(Console.ReadLine());
                for (int i = 0; i < n; i++)
                {

                    Console.WriteLine("Enter Id:");
                    int  Id = Convert.ToInt32(Console.ReadLine());

                    Console.WriteLine("Enter First name:");
                    string f_name = Console.ReadLine();

                    Console.WriteLine("Enter Last name:");
                    string l_name = Console.ReadLine();

                    Console.WriteLine("Enter Salary:");
                    int  sal =Convert.ToInt32(Console.ReadLine());

                    Console.WriteLine("Enter Gender:");
                    int gen = Convert.ToInt32(Console.ReadLine());
                  Gender gen1=ReturnGender(gen);

                    Console.WriteLine("Enter Country:");
                    int cntry = Convert.ToInt32(Console.ReadLine());
                    Country con = ReturnCountry(cntry);

                     employeeList.Add(new Emp() { ID=Id,First_Name=f_name,Last_Name=l_name,Salary=sal,gender=gen1,Country1=con });
                }
            }
            catch(Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
        public Gender ReturnGender(int gen)
        {
            Gender gender=Gender.Unknown;
            switch (gen)
            {
                case 0:gender=Gender.Male;
                    break;
                case 1: gender = Gender.Female;
                    break;
                case 2: gender = Gender.Unknown;
                    break;
            }
            return gender;
        }
        public Country ReturnCountry(int con)
        {
            Country country=Country.India;
            switch (con)
            {
                case 0:country=Country.India;
                    break;
                case 1:country = Country.Japan;
                    break;
                case 2:country = Country.Australia;
                    break;
                case 3:country = Country.US;
                    break;
                         
            }
            return country;
           
        }
        public void  ReturnMinsalary(Gender gender)
        {
            int min = int.MaxValue;
            int index = 0, i = 0;
            foreach (Emp e in employeeList)
            {
                if (e.Salary < min&&gender==Gender.Male)
                {
                    min = e.Salary;
                    index = i;
                }
                i++;
            }
            Emp e1 = employeeList.ElementAt(index);
            Console.WriteLine(e1.ID + "\t" + e1.First_Name + "\t" + e1.Last_Name+"\t"+e1.Salary);

        }
        public void ReturnMaxsalary(Gender gender)
        {
            int max = 0;
            int index=0,i=0;

            foreach (Emp e in employeeList)
            {
                if (e.Salary > max && gender == Gender.Male)
                {
                    max = e.Salary;
                    index = i;
                }
                i++;
            }
            Emp e1 = employeeList.ElementAt(index);
            Console.WriteLine(e1.ID + "\t" + e1.First_Name + "\t" + e1.Last_Name+"\t"+e1.Salary);

        }
        public void Display_All_Employee_Details()
        {
            foreach (Emp e in employeeList)
            {
                Console.WriteLine(e.ID + "\t" + e.First_Name + "\t" + e.Last_Name);
            }
        }
        public string checkGender(Gender gender)
        {
            string gender1 = "unknown";
            switch(gender)
            {
                case Gender.Male:gender1="male";
                    break;
                case Gender.Female:
                    gender1 = "female";
                    break;
                case Gender.Unknown:
                    gender1 = "unknown";
                    break;
            }
            return gender1;

        }
        public void Sort_Employee()
        {
            List<Emp> SortedList = employeeList.OrderBy(emp => emp.Salary).ToList();
            List<Emp> SortedList1 = employeeList.OrderBy(emp => emp.gender).ToList();
            Console.WriteLine("Sorting employee list based on salary:....\n");
            foreach (Emp e in SortedList)
            {
                Console.WriteLine(e.ID + "\t" + e.First_Name + "\t" + e.Last_Name+"\t"+e.Salary);
            }
            Console.WriteLine("Sorting employee list based on Gender:....\n");
            foreach (Emp e in SortedList1)
            {
                Console.WriteLine(e.ID + "\t" + e.First_Name + "\t" + e.Last_Name+"\t"+checkGender(e.gender));
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            int ch;
            Database obj = new Database();
            do
            {
                Console.WriteLine("\n1:Accept Employee\n2:find min salary\n3:find max salary\n4:sort employee\n5:display all Employee\n6:exit\nEnter your choice:\n");
                ch = Convert.ToInt32(Console.ReadLine());
                switch (ch)
                {
                    case 1:obj.Accept_Employee();
                        break;
                    case 2:obj.ReturnMinsalary(Gender.Male);
                        break;
                    case 3:obj.ReturnMaxsalary(Gender.Male);
                        break;
                    case 4:obj.Sort_Employee();
                        break;
                    case 5:obj.Display_All_Employee_Details();
                        break;

                    case 6:System.Environment.Exit(0);
                        break;
                }
                    
            } while (ch != 6);
                
        }
    }
}
