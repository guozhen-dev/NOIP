#include <bits/stdc++.h>
using namespace std;

struct student {
	string name;
	int final_score;
	int called_score;
	bool manager;
	bool western;
	int essay;
	int tot_money;
};
vector<student> pq;
int main(){
	int T;
	cin >> T;
	for (int i = 0 ; i < T ;i++){
 		struct student student_current;
		cin >> student_current.name >>student_current.final_score>>student_current.called_score;
		char man , wes;
		cin >> man>>wes;
	  student_current.manager=(man=='Y'?true:false);
		student_current.western=(wes=='Y'?true:false);
		cin >> student_current.essay;
		student_current.tot_money =0 ;
		if(student_current.final_score>80 and student_current.essay>=1) student_current.tot_money+=8000;
		if(student_current.final_score>85 and student_current.called_score>80) student_current.tot_money+=4000;
		if(student_current.final_score>90) student_current.tot_money+=2000;
		if(student_current.final_score>85 and student_current.western ) student_current.tot_money+=1000;
		if(student_current.called_score>80 and student_current.manager) student_current.tot_money+=850;
		pq.push_back(student_current);
	}
	int max_money=INT_MIN;
	int tot_given_money = 0;
	for(int i = 0 ; i<pq.size() ;i++){
		max_money=max(max_money,pq[i].tot_money);
		tot_given_money += pq[i].tot_money;
	}
	for(int i = 0 ; i<pq.size() ;i++){
		if(max_money == pq[i].tot_money){
			cout << pq[i].name<<endl;
			cout << pq[i].tot_money<<endl;
			cout << tot_given_money<<endl;
			exit(0);
		}
	}
	return 0;
}

	/*
	 * 院士奖学金，每人8000元，期末平均成绩高于80分（>80），并且在本学期内发表1篇或1篇以上论文的学生均可获得；
	 * 五四奖学金，每人4000元，期末平均成绩高于85分（>85），并且班级评议成绩高于80分（>80）的学生均可获得；
	 * 成绩优秀奖，每人2000元，期末平均成绩高于90分（>90）的学生均可获得；
	 * 西部奖学金，每人1000元，期末平均成绩高于85分(>85）的西部省份学生均可获得；
	 * 班级贡献奖，每人850元，班级评议成绩高于80分（>80）的学生干部均可获得；
	 */
