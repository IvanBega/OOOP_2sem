using project.Model;
using project.Utils;
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
        private double _entryReps3 = 0;
        private double _entryWeights3 = 0;
        private double _entryReps4 = 0;
        private double _entryWeights4 = 0;
        private string exerciseName;
        private int _amountOfSets = 0;
        private string errorLabel = "";
        private bool errorVisible = false;
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
        public double EntryReps3
        {
            get { return _entryReps3; }
            set { _entryReps2 = value; NotifyPropertyChanged(); }
        }
        public double EntryReps4
        {
            get { return _entryReps4; }
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
        public double EntryWeights3
        {
            get { return _entryWeights3; }
            set { _entryWeights2 = value; NotifyPropertyChanged(); }
        }
        public double EntryWeights4
        {
            get { return _entryWeights4; }
            set { _entryWeights2 = value; NotifyPropertyChanged(); }
        }

        public string ErrorLabel
        {
            get { return errorLabel; }
            set { errorLabel = value; NotifyPropertyChanged(); }
        }

        public bool ErrorVisible
        {
            get { return errorVisible; }
            set { errorVisible = value; NotifyPropertyChanged(); }
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
            if (!ValidateData())
            {
                ErrorLabel = "Дані введені некоректно!";
                ErrorVisible = true;
                return;
            }

            double average_reps = (EntryReps1 + EntryReps2 + EntryReps3 + EntryReps4) / _amountOfSets;
            double average_weights = (EntryWeights1 + EntryWeights2 + EntryWeights3 + EntryWeights4) / _amountOfSets;

            LogModel newLog = new LogModel();
            newLog.Date = DateTime.Now.ToString("dd/MM/yyyy");
            newLog.Weights = (float)average_weights;
            newLog.Reps = (float)average_reps;
            newLog.Sets = _amountOfSets;

            MainViewModel.AddLog(newLog, exerciseName);
            await PopupNavigation.Instance.PopAsync();
        }

        private bool ValidateData()
        {
            _amountOfSets = 0;
            try
            {     
                if (EntryReps1 != 0 && EntryWeights1 != 0) _amountOfSets++;
                if (EntryReps2 != 0 && EntryWeights2 != 0) _amountOfSets++;
                if (EntryReps3 != 0 && EntryWeights3 != 0) _amountOfSets++;
                if (EntryReps4 != 0 && EntryWeights4 != 0) _amountOfSets++;
                if (_amountOfSets == 0) return false;

                if (EntryReps1 < 0 || EntryReps2 < 0 || EntryReps3 < 0 || EntryReps4 < 0)
                {
                    return false;
                }
                if (EntryWeights1 < 0 || EntryWeights2 < 0 || EntryWeights3 < 0 || EntryWeights4 < 0)
                {
                    return false;
                }
                if (EntryReps1 > Constants.MaxEntryReps || EntryReps2 > Constants.MaxEntryReps || EntryReps3 > Constants.MaxEntryReps || EntryReps4 > Constants.MaxEntryReps)
                {
                    return false;
                }
                if (EntryWeights1 > Constants.MaxEntryWeights || EntryWeights2 > Constants.MaxEntryWeights || EntryWeights3 > Constants.MaxEntryWeights || EntryWeights4 > Constants.MaxEntryWeights)
                {
                    return false;
                }
                return true;
            }
            catch
            {
                return false;
            }
        }

        private async void BackButtonClicked()
        {
            await PopupNavigation.Instance.PopAsync();
        }
    }
}
