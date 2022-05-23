using project.Model;
using Rg.Plugins.Popup.Services;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Globalization;
using System.Text;
using Xamarin.Forms;

namespace project.ViewModel
{
    public class RemoveExercisePopupViewModel
    {
        public Command BackButtonCommand { get; set; }
        public Command RemoveCommand { get; set; }
        public ObservableCollection<ExerciseModel> ExerciseList { get; set; }
        public RemoveExercisePopupViewModel()
        {
            ObservableCollection<ExerciseModel> dataToLoad = LoadList();
            ExerciseList = dataToLoad;
            BackButtonCommand = new Command(BackButtonClicked);
            RemoveCommand = new Command(RemoveClicked);
        }
        private ObservableCollection<ExerciseModel> LoadList()
        {
            ObservableCollection<ExerciseModel> data = new ObservableCollection<ExerciseModel>();
            foreach (ExerciseModel em in MainViewModel.ExerciseList)
                data.Add(em);
            Sort(data, SortByName);
            // add sort
            return data;

        }
        public async void BackButtonClicked()
        {
            await PopupNavigation.Instance.PopAsync(false);
        }
        public async void RemoveClicked()
        {
            throw new NotImplementedException();
        }

        private void Sort<T>(ObservableCollection<T> collection, Comparison<T> comparison)
        {
            // https://stackoverflow.com/a/36642852/17773990
            var sortableList = new List<T>(collection);
            sortableList.Sort(comparison);

            for (int i = 0; i < sortableList.Count; i++)
            {
                collection.Move(collection.IndexOf(sortableList[i]), i);
            }
        }
        private int SortByName(ExerciseModel a, ExerciseModel b)
        {
            string lhs = a.Name;
            string rhs = b.Name;
            return lhs.CompareTo(rhs);
        }
        private int SortByDate(LogModel a, LogModel b)
        {
            DateTime lhs = DateTime.ParseExact(a.Date, "dd/mm/yy", CultureInfo.InvariantCulture);
            DateTime rhs = DateTime.ParseExact(b.Date, "dd/mm/yy", CultureInfo.InvariantCulture);
            return lhs.CompareTo(rhs);
        }
    }
}
