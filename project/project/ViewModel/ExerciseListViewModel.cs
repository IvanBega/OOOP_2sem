using project.Views.Popups;
using Rg.Plugins.Popup.Contracts;
using Rg.Plugins.Popup.Services;
using System;
using System.Collections.Generic;
using System.Text;
using Xamarin.Forms;

namespace project.ViewModel
{
    public class ExerciseListViewModel
    {
        private ExercisePopup _exercisePage;
        private IPopupNavigation _popup { get; set; }
        public ExerciseListViewModel()
        {
            BackButtonCommand = new Command(BackButtonClicked);
            AddExerciseCommand = new Command(AddButtonClicked);
            RemoveExerciseCommand = new Command(RemoveButtonClicked);

            _popup = PopupNavigation.Instance;
            _exercisePage = new ExercisePopup();
        }

        private void RemoveButtonClicked(object obj)
        {
            throw new NotImplementedException();
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
    }
}
