using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using project.Model;
using project.ViewModel;
using project.Views.Popups;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace project.Views
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class ExerciseListPage : ContentPage
    {
        public ExerciseListPage()
        {
            InitializeComponent();
            BindingContext = new ViewModel.ExerciseListViewModel();
        }

        private async void ListView_ItemTapped(object sender, ItemTappedEventArgs e)
        {
            if (e.Item == null)
                return;
            ((ListView)sender).SelectedItem = null; // deselect
            var content = e.Item as ExerciseModel;
            await Application.Current.MainPage.Navigation.PushAsync(new ExercisePage());
        }
    }
}