using project.Model;
using project.Views.Popups;
using Rg.Plugins.Popup.Contracts;
using Rg.Plugins.Popup.Services;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Globalization;
using System.Text;
using Xamarin.Forms;

namespace project.ViewModel
{
    public class ExerciseListViewModel
    {
        private ExercisePopup _exercisePage;
        private RemoveExercisePopup _removeExercisePage;
        private IPopupNavigation _popup { get; set; }
        public ObservableCollection<ExerciseModel> ExerciseList { get; set; }
        public ExerciseListViewModel()
        {
            ExerciseList = LoadList();
            Sort(ExerciseList, SortByName);
            foreach (ExerciseModel em in ExerciseList)
            {
                em.Data.Sort(SortByDate);
            }
            BackButtonCommand = new Command(BackButtonClicked);
            AddExerciseCommand = new Command(AddButtonClicked);
            RemoveExerciseCommand = new Command(RemoveButtonClicked);

            _popup = PopupNavigation.Instance;
            _exercisePage = new ExercisePopup();
            _removeExercisePage = new RemoveExercisePopup();
        }

        private int SortByName(ExerciseModel a, ExerciseModel b)
        {
            string a1 = a.Name; string b1 = b.Name; return a1.CompareTo(b1);
        }

        private async void RemoveButtonClicked(object obj)
        {
            await _popup.PushAsync(_removeExercisePage);
        }

        private async void AddButtonClicked(object obj)
        {
            await _popup.PushAsync(_exercisePage);
        }

        public Command BackButtonCommand { get; set; }
        public Command AddExerciseCommand { get; set; }
        public Command RemoveExerciseCommand { get; set; }
        private void BackButtonClicked(object obj)
        {
            Application.Current.MainPage.Navigation.PopAsync();
        }

        private ObservableCollection<ExerciseModel> LoadList()
        {
            ObservableCollection<ExerciseModel> data = new ObservableCollection<ExerciseModel>();
            foreach (ExerciseModel em in MainViewModel.ExerciseList)
                data.Add(em);

            return data;
        }

        int SortByDate(LogModel a, LogModel b)
        {
            DateTime a1 = DateTime.ParseExact(a.Date, "dd/MM/yyyy", CultureInfo.InvariantCulture);
            DateTime b1 = DateTime.ParseExact(b.Date, "dd/MM/yyyy", CultureInfo.InvariantCulture);
            return a1.CompareTo(b1) * -1;
        }

        private void Sort<T>(ObservableCollection<T> collection, Comparison<T> comparison)
        {
            var sortableList = new List<T>(collection);
            sortableList.Sort(comparison);

            for (int i = 0; i < sortableList.Count; i++)
            {
                collection.Move(collection.IndexOf(sortableList[i]), i);
            }
        }
    }
}
