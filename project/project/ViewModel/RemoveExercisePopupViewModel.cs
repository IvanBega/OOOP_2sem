using project.Model;
using Rg.Plugins.Popup.Services;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
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
    }
}
