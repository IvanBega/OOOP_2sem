using project.Model;
using SQLite;
using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Threading.Tasks;
using Xamarin.Forms;
using SQLiteNetExtensions;
using SQLiteNetExtensionsAsync;

namespace project.Repository
{
    public class ExerciseRepository : IRepository
    {
        public ExerciseRepository()
        {
            string DatabaseFilename = "Repository.db3";
            var basePath = Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData);
            var path = Path.Combine(basePath, DatabaseFilename);
            Database = new SQLiteConnection(path, SQLite.SQLiteOpenFlags.ReadWrite | SQLite.SQLiteOpenFlags.Create | SQLite.SQLiteOpenFlags.SharedCache);
            //InitializeList();
        }
        private void InitializeList()
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
            logModel2.Weights = 100;
            var logModelList = new List<LogModel>();
            logModelList.Add(logModel);
            logModelList.Add(logModel2);
            model.Data = logModelList;
            model.Name = "Exercise 1";

            SaveItem(model);
        }

        static SQLiteConnection Database;
        public static readonly AsyncLazy<ExerciseRepository> Instance = new AsyncLazy<ExerciseRepository>(() =>
        {
            var instance = new ExerciseRepository();
            CreateTableResult result = Database.CreateTable<ExerciseModel>();
            return instance;
        });
        public List<ExerciseModel> GetItemsAsync()
        {
            //return Database.Table<ExerciseModel>().ToListAsync();
            return SQLiteNetExtensions.Extensions.ReadOperations.GetAllWithChildren<ExerciseModel>(Database);
            //return Database.GetAllWithChildren<ExerciseModel>();
        }
        public void SaveItem(ExerciseModel item)
        {
            SQLiteNetExtensions.Extensions.WriteOperations.InsertWithChildren(Database, item);
            //Database.Insert(item);
        }
        public void DeleteItem(ExerciseModel item)
        {
            Database.Delete(item);
        }
    }
}
