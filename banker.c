#0
struct pro{
int all[10],max[10],need[10];
int flag;
};
int i,j,pno,r,nr,id,k=0,safe=0,exec,count=0,wait=0,max_err=0;
struct pro p[10];
int aval[10],seq[10];
void safeState()
{
while(count!=pno){
safe = 0;
for(i=0;i<pno;i++){
if(p[i].flag){
exec = r;
for(j=0;j<r;j++)
{
if(p[i].need[j]>aval[j]){
exec =0;
}
}
if(exec == r){
for(j=0;j<r;j++){
aval[j]+=p[i].all[j];
}
p[i].flag = 0;
seq[k++] = i;
safe = 1;
count++;
}
}
}
if(!safe)
{
printf("System is in Unsafe State\n");
break;
}
}
if(safe){
printf("\n\nSystem is in safestate \n");
printf("Safe State Sequence \n");
for(i=0;i<k;i++)
printf("P[%d] ",seq[i]);
printf("\n\n");
}
}
void reqRes(){
printf("\nRequest for new Resourses");
printf("\nProcess id ? ");
scanf("%d",&id);
printf("Enter new Request details ");
for(i=0;i<r;i++){
scanf("%d",&nr);
if( nr <= p[id].need[i])
{
if( nr <= aval[i]){
aval[i] -= nr;
p[id].all[i] += nr;
p[id].need[i] -= nr;
}
else
wait = 1;
}
else
max_err = 1;
}
if(!max_err && !wait)
safeState();
else if(max_err){
printf("\nProcess has exceeded its maximum usage \n");
}
else{
printf("\nProcess need to wait\n");
}
}
void main()
{
printf("Enter no of process ");
scanf("%d",&pno);
printf("Enter no. of resourses ");
scanf("%d",&r);
printf("Enter Available Resourse of each type ");
for(i=0;i<r;i++){
scanf("%d",&aval[i]);
}
printf("\n\n---Resourse Details---");
for(i=0;i<pno;i++){
printf("\nResourses for process %d\n",i);
printf("\nAllocation Matrix\n");
for(j=0;j<r;j++){
scanf("%d",&p[i].all[j]);
}
printf("Maximum Resourse Request \n");
for(j=0;j<r;j++){
scanf("%d",&p[i].max[j]);
}
p[i].flag = 1;
}
// Calcualting need
(i=0;i<pno;i++){
for(j=0;j<r;j++){
p[i].need[j] = p[i].max[j] - p[i].all[j];
}
}
//Print Current Details
printf("\nProcess Details\n");
printf("Pid\t\tAllocattion\t\tMax\t\tNeed\n");
for(i=0;i<pno;i++) {
printf("%d\t\t",i);
for(j=0;j<r;j++){
printf("%d ",p[i].all[j]);
}
printf("\t\t");
for(j=0;j<r;j++){
printf("%d ",p[i].max[j]);
}
printf("\t\t");
for(j=0;j<r;j++){
printf("%d ",p[i].need[j]);
}
printf("\n");
}
//Determine Current State in Safe State
safeState();
int ch=1;
do{
printf("Request new resourse ?[0/1] :");
scanf("%d",&ch);
if(ch)
req
}while(ch!=0);
printf("\n");
  
dbms

[4/21,  /*Lab Exam Question 3*/

/*Actor*/

Create table Actor(
	Actor_id int not null primary key,
    Name varchar(15),
    Gender varchar(1) Check(Gender = 'F' OR Gender = 'M')
);

Insert into Actor Values(1,'PQR','M');
Insert into Actor Values(2,'XYZ','F');
Insert into Actor Values(3,'Priyanka','F');

Select * from Actor;

/*Actor_dates*/

Create table Actor_dates(
	Actor_id int not null references Actor(Actor_id),
    Available_from DATE,
    Available_to DATE
);

Insert into Actor_dates Values(1,'2020-10-21','2020-11-21');
Insert into Actor_dates Values(2,'2020-11-21','2020-12-21');
Insert into Actor_dates Values(3,'2020-08-21','2020-09-21');

Select * from Actor_dates;
SET FOREIGN_KEY_CHECKS = 0;
truncate table Actor_dates;
truncate table Actor;
truncate table Actor_films;
truncate table Cinema;

/*Cinema*/

Create table Cinema(
	film_id varchar(6) not null primary key check(film_id like 'F%'),
    filmname varchar(15),
    start_date DATE,
    end_date DATE,
    release_date DATE,
    budget_allocated real
);
Insert into Cinema Values('F1','KKK','2020-10-21','2020-11-21','2021-01-01',20000000);
Insert into Cinema Values('F2','CCC','2020-08-21','2020-09-21','2020-12-01',40000000);
Insert into Cinema Values('F3','VVV','2020-08-21','2020-09-21','2020-12-01',4000000);

Select * from Cinema;

/*Actor_films*/

Create table Actor_films(
	Actor_id int not null references Actor(Actor_id),
	film_id varchar(6) not null references Cinema(film_id),
    actor_contract_amount real
);

Insert into Actor_films Values(1,'F1',400000);
Insert into Actor_films Values(2,'F1',300000);
Insert into Actor_films Values(3,'F2',600000);
Insert into Actor_films Values(2,'F2',300000);
Insert into Actor_films Values(1,'F3',700000);
Insert into Actor_films Values(2,'F3',300000);

Select * from Actor_films;

/*Query 1*/
Select * from Actor where Actor_id NOT IN(Select f.Actor_id from Actor_films as f,Cinema as c where c.film_id = f.film_id and c.filmname = 'KKK');

/*Query 2*/
Select f.film_id from Actor_films as f,Actor as a where a.Actor_id = f.Actor_id AND a.Name = 'PQR' and f.film_id IN(Select f.film_id from Actor_films as f,Actor as a where a.Actor_id = f.Actor_id AND a.Name = 'XYZ');

/*Query 3*/
Select * from Actor where Actor_id IN(Select a.Actor_id from Actor_films as f,Actor as a ,Cinema as c where a.Actor_id = f.Actor_id AND c.film_id = f.film_id AND c.release_date like '_____12___');

/*Query 4*/
Select * from Actor where Gender = 'F' AND Actor_id = (Select Actor_id from Actor_dates group by Actor_id order by (Available_from + Available_to) desc LIMIT 1);

/*Package*/

/*Query 5*/
delimiter $$
	CREATE PROCEDURE P1()
    BEGIN
		Select DISTINCT a.* from Actor_films as f,Actor as a,Cinema as c where a.Actor_id = f.Actor_id AND c.film_id = f.film_id AND c.budget_allocated > 10000000 AND c.budget_allocated < 100000000; 
    END;
$$

CALL P1();

/*Query 6*/
delimiter $$
	CREATE TRIGGER T1 BEFORE INSERT ON Cinema FOR EACH ROW
    BEGIN
		IF new.start_date > new.end_date Then
			signal sqlstate '45000';
        END IF;
    END;
$$

Insert into Cinema Values('F5','dVV','2021-08-21','2020-12-21','2020-12-01',4000000);
 
 
[4/21, 5:20 AM] Akash R ASET: /*Lab Exam Question 2*/
CREATE TABLE `Employee` (
  `Emp_id` int NOT NULL,
  `Name` varchar(20) DEFAULT NULL,
  `DoB` date DEFAULT NULL,
  `Salary` double DEFAULT NULL,
  PRIMARY KEY (`Emp_id`),
  CONSTRAINT `Employee_chk_1` CHECK ((`Salary` >= 5000))
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;


Insert into Location Values(1,'Palakkad',678001);

Select * from Location;
SET FOREIGN_KEY_CHECKS = 0;
truncate table Location;

Insert into Employee Values(1,'Anandu','2023-06-21',45000);
Insert into Employee Values(2,'Sreyas','2000-06-22',55000);
Insert into Employee Values(3,'Akhilesh','2000-05-19',25000);
Insert into Employee Values(4,'Vaishnav','2000-05-06',7000);
Insert into Employee Values(5,'PQR','2000-05-16',17000);
Insert into Employee Values(6,'John','2000-05-17',17000);
Insert into Employee Values(7,'Arun','2000-05-18',16000);

Select * from Employee;
SET FOREIGN_KEY_CHECKS = 0;
truncate table Employee;

Insert into Department Values('D1','ABC',2,1);
Insert into Department Values('D2','BBC',5,1);
Insert into Department Values('D3','CBC',5,1);


Select * from Department;
SET FOREIGN_KEY_CHECKS = 0;
truncate table Department;

Insert into Works Values(1,'D1');
Insert into Works Values(2,'D1');
Insert into Works Values(3,'D2');
Insert into Works Values(4,'D3');
Insert into Works Values(5,'D3');
Insert into Works Values(5,'D2');
Insert into Works Values(6,'D2');
Insert into Works Values(7,'D1');

Select * from Works;
SET FOREIGN_KEY_CHECKS = 0;
truncate table Works;

/*Query 1*/
Select e.* from Employee as e,Works as w,Department as d where e.Emp_id = w.Emp_id AND w.Dep_id = d.Dep_id AND d.dept_name = 'ABC'; 

/*Query 2*/
Select count(*) from Works as w group by w.Dep_Id having w.Dep_Id IN (Select w.Dep_Id from Employee as e,Works as w where e.Emp_id = w.Emp_id AND (e.Name = 'John' OR e.Name = 'Arun'));

/*Query 3*/
Select * from Employee where Salary > 12000 AND Salary < 25000;

/*Query 4*/
Select d.* from Employee as e,Department as d where e.Emp_id = d.manager_id AND e.Name = 'PQR';

/*Query 5*/
Select * from Department as d where Dep_id = (Select Dep_id from Works group by Dep_id order by count(*) desc LIMIT 1);

/*Package*/

/*Query 6*/
delimiter $$
   
   CREATE PROCEDURE find_emp()
   BEGIN 
      Select count(*) from Employee where Salary > (Select avg(Salary) from Employee);
   END; 
$$
 
CALL find_emp();

/*Query 7*/

delimiter $$
	CREATE PROCEDURE DispDeptSalary()
    BEGIN
		Select d.*,e.Salary from Employee as e,Works as w,Department as d where e.Emp_id = w.Emp_id AND w.Dep_id = d.Dep_id ;
    END;
$$

CALL DispDeptSalary();

/*Query 8*/
delimiter $$
	CREATE PROCEDURE DispEmp()
    begin
				Select e.* from Employee as e ,Works as w where w.Emp_id = e.Emp_id AND e.Salary < 12000 AND w.Dep_id IN (Select d.Dep_id from Department as d,Employee as e where d.manager_id = e.Emp_id AND e.Salary > 30000);
    end;
$$

call DispEmp();
[4/21, 5:20 AM] Akash R ASET: /*Lab Exam Question 4*/

/*Sailors*/

Create Table Sailors(
	Sid int not null primary key,
	Sname varchar(45),
	Rating int,
	Age real);

Insert into Sailors values(1,'Anandu',4,21);
Insert into Sailors values(2,'Akhil',3,23);
Insert into Sailors values(3,'Akhilesh',4,22);
Insert into Sailors values(4,'Akash',22,22);

Select * from Sailors;

/*Boats*/
Create Table Boats(
	Bid int not null primary key,
    Bname varchar(45),
    Color varchar(25)
);

Insert into Boats values(1,'Avast','Red');
Insert into Boats values(2,'Garde','Blue');

Select * from Boats;

/*Reserves*/
Create Table Reserves(
	Sid int not null references Sailors(Sid),
    Bid int not null references Boats(Bid),
    Day DATE
);

Insert into Reserves values(1,1,'2020-09-12');
Insert into Reserves values(2,1,'2020-09-12');
Insert into Reserves values(3,2,'2021-09-12');

Select * from Reserves;


/*Query 1*/
Select s.Sname from Sailors as s,Boats as b,Reserves as r where r.Sid = s.Sid AND r.Bid = b.Bid AND b.Color = 'Red';

/*Query 2*/
Select DISTINCT s.Sname from Sailors as s,Reserves as r where r.Sid = s.Sid;

/*Query 3*/
Select Rating from Sailors where Rating = (Select avg(age) from Sailors);

/*Package*/

/*Query 4*/
delimiter $$
	Create function f1(Color Varchar(25))
    returns int
    DETERMINISTIC
    begin
		return (Select count(*) from Boats as b,Reserves as r where r.Bid = b.Bid AND b.Color = Color);
    end;
$$

Select f1('Blue');

/*Query 5*/
delimiter $$
	CREATE TRIGGER Sid_Delete AFTER DELETE On Sailors FOR EACH ROW
    BEGIN
		Delete from Reserves where Sid = Old.Sid;
    END;
$$

Select * from Reserves;
SET SQL_SAFE_UPDATES = 0;
Delete from Sailors where Sid = 3;
