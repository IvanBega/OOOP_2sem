using System;
using System.Collections.Generic;
using System.Text;
using Xamarin.Forms;
using project.Views;
using project.Model;
using project.Repository;
namespace project.ViewModel
{
    public class MainViewModel : BaseViewModel
    {
        public static List<ExerciseModel> ExerciseList { get; set; } = new List<ExerciseModel>();
        private static ExerciseRepository database;
        public MainViewModel()
        {

            ExerciseCommand = new Command(ExerciseClicked);
            InitializeList();

        }
        private async void InitializeList()
        {
            database = await ExerciseRepository.Instance;
            ExerciseList = database.GetAllItems();
        }
        public Command ExerciseCommand { get; set; }
        private void ExerciseClicked()
        {
            Application.Current.MainPage.Navigation.PushAsync(new ExerciseListPage());
        }
        public async static void AddExercise(string entry)
        {
            if (ExerciseList.Count > Utils.Constants.MaxExerciseCount)
            {
                return;
            }
            ExerciseModel newExercise = new ExerciseModel();
            newExercise.Name = entry;

            List<LogModel> newData = new List<LogModel>();
            LogModel data = new LogModel();

            newExercise.Data = newData;

            ExerciseList.Add(newExercise);
            database.SaveItem(newExercise);
            await App.Current.MainPage.Navigation.PopToRootAsync();
            await Application.Current.MainPage.Navigation.PushAsync(new Views.ExerciseListPage());

        }
        public async static void RemoveExercise(ExerciseModel exercise)
        {
            ExerciseList.Remove(exercise);
            database.DeleteItem(exercise);
            await App .Current.MainPage.Navigation.PopToRootAsync();
            await Application .Current.MainPage.Navigation.PushAsync(new Views.ExerciseListPage());

        }
        public async static void AddLog(LogModel log, string exerciseName)
        {
            ExerciseModel exercise = null;
            foreach (ExerciseModel em in ExerciseList)
            {
                if (em.Name.Equals(exerciseName))
                {
                    database.DeleteItem(em);

                    exercise = em;
                    em.Data.Insert(0, log);
                    if (em.Data.Count > Utils.Constants.MaxLogPerExerciseCount)
                    {
                        em.Data.RemoveAt(em.Data.Count - 1);
                    }
                    
                    database.SaveItem(em);
                }
            }
            await App.Current.MainPage.Navigation.PopToRootAsync();
            await Application.Current.MainPage.Navigation.PushAsync(new Views.ExerciseListPage());
            await Application.Current.MainPage.Navigation.PushAsync(new Views.Popups.ExercisePage(exercise));
        }
    }
}
