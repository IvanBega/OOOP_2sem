using System;
using System.Collections.Generic;
using System.Text;
using Xamarin.Forms;
using project.Views;
using project.Model;

namespace project.ViewModel
{
    public class MainViewModel : BaseViewModel
    {
        public static List<ExerciseModel> ExerciseList { get; set; }
        public MainViewModel()
        {
            ExerciseCommand = new Command(ExerciseClicked);
            ExerciseList = new List<ExerciseModel>();

        }
        public Command ExerciseCommand { get; set; }
        private void ExerciseClicked()
        {
            Application.Current.MainPage.Navigation.PushAsync(new ExerciseListPage());
            //Navigation
        }
        public static void AddExercise(string entry)
        {
            ExerciseModel newExercise = new ExerciseModel();
            newExercise.Name = entry;

            List<LogModel> newData = new List<LogModel>();
            LogModel data = new LogModel();
            data.Reps = 0;
            data.Sets = 0;
            data.Weights = 0;
            data.Date = DateTime.Now.ToString("dd/MM/yy");
            newData.Add(data);

            newExercise.Data = newData;

            ExerciseList.Add(newExercise);
            App.Current.MainPage.Navigation.PopToRootAsync();
            Application.Current.MainPage.Navigation.PushAsync(new Views.ExerciseListPage());
        }
    }
}
