using Rg.Plugins.Popup.Services;
using System;
using System.Collections.Generic;
using System.Text;
using Xamarin.Forms;

namespace project.ViewModel
{
    public class ExercisePopupViewModel : BaseViewModel
    {
        private string entry = "";
        public Command BackButtonCommand { get; set; }
        public Command ConfirmCommand { get; set; }
        public string Entry
        {
            get { return entry; }
            set { entry = value; NotifyPropertyChanged(); }
        }
        public ExercisePopupViewModel()
        {
            BackButtonCommand = new Command(BackButtonClicked);
            ConfirmCommand = new Command(ConfirmClicked);
        }

        private async void ConfirmClicked(object obj)
        {
            MainViewModel.AddExercise(Entry);
            await PopupNavigation.Instance.PopAsync(false);
        }

        private async void BackButtonClicked(object obj)
        {
            await PopupNavigation.Instance.PopAsync(false);
        }

        
    }
}
