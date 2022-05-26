using project.Model;
using Rg.Plugins.Popup.Services;
using System;
using System.Collections.Generic;
using System.Text;
using Xamarin.Forms;

namespace project.ViewModel
{
    public class LogPopupViewModel : BaseViewModel
    {
        private double _entryReps1 = 0;
        private double _entryWeights1 = 0;
        private double _entryReps2 = 0;
        private double _entryWeights2 = 0;
        private string exerciseName;
        public double EntryReps1
        {
            get { return _entryReps1; }
            set { _entryReps1 = value; NotifyPropertyChanged(); }
        }
        public double EntryReps2
        {
            get { return _entryReps2; }
            set { _entryReps2 = value; NotifyPropertyChanged(); }
        }
        public double EntryWeights1
        {
            get { return _entryWeights1; }
            set { _entryWeights1 = value; NotifyPropertyChanged(); }
        }
        public double EntryWeights2
        {
            get { return _entryWeights2; }
            set { _entryWeights2 = value; NotifyPropertyChanged(); }
        }
        public string LogDate { get; set; }
        public Command BackButtonCommand { get; set; }
        public Command ConfirmCommand { get; set; }
        public LogPopupViewModel(string eName)
        {
            exerciseName = eName;
            LogDate = DateTime.Now.ToString("dd/MM/yy");
            BackButtonCommand = new Command(BackButtonClicked);
            ConfirmCommand = new Command(ConfirmCommandClicked);
        }

        private async void ConfirmCommandClicked()
        {
            //await ValidateData();
            double amount_of_sets = 0;
            if (EntryReps1 != 0 && EntryWeights1 != 0) amount_of_sets++;
            if (EntryReps2 != 0 && EntryWeights2 != 0) amount_of_sets++;
            double average_reps = (EntryReps1 + EntryReps2) / amount_of_sets;
            double average_weights = (EntryWeights1 + EntryWeights2) / amount_of_sets;
            LogModel newLog = new LogModel();
            newLog.Date = DateTime.Now.ToString("dd/MM/yyyy");
            newLog.Weights = (float)average_weights;
            newLog.Reps = (float)average_reps;

            MainViewModel.AddLog(newLog, exerciseName);
            await PopupNavigation.Instance.PopAsync();
        }

        private async void ValidateData()
        {
            throw new NotImplementedException();
        }

        private async void BackButtonClicked()
        {
            await PopupNavigation.Instance.PopAsync();
        }
    }
}
