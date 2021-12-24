int final_grade(int exam, int proj){
   return exam > 90 || proj > 10 ? 100 
         :exam > 75 && proj >= 5 ? 90
         :exam > 50 && proj >= 2 ? 75 : 0;
}