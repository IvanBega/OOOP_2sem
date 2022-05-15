using project.ViewModel;
using System;
using System.Collections.Generic;
using System.Text;
using project.Repository;
namespace project.DataService
{
    public class UserDataService
    {
        private static UserDataService instance;
        private MainViewModel mainViewModel;
        public UserDataService()
        {

        }
        public static UserDataService Instance => instance ?? (instance = new UserDataService());
        public MainViewModel MainViewModel => this.mainViewModel ?? (this.mainViewModel = new MainViewModel(new ExerciseRepository()));
    }
}
