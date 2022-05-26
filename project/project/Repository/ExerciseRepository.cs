using project.Model;
using System;
using System.Collections.Generic;
using System.Text;
namespace project.Repository
{
    public class ExerciseRepository : IRepository
    {
        public List<ExerciseModel> GetExerciseList()
        {
            ExerciseModel model = new ExerciseModel();
            LogModel logModel = new LogModel();
            logModel.Date = "22/05/22";
            logModel.Reps = 3;
            logModel.Sets = 2;
            logModel.Weights = 10;
            LogModel logModel2 = new LogModel();
            logModel2.Date = "22/05/22";
            logModel2.Reps = 3;
            logModel2.Sets = 2;
            logModel2.Weights = 10;
            var logModelList = new List<LogModel>();
            logModelList.Add(logModel);
            logModelList.Add(logModel2);
            model.Data = logModelList;
            model.Name = "Exercise 1";

            var list = new List<ExerciseModel>();
            list.Add(model);
            model.Name = "Exercise 2";
            list.Add(model);
            return list;
        }
    }
}
