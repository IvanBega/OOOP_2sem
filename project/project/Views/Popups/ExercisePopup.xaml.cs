﻿using Rg.Plugins.Popup.Services;
using System;
using System.Threading.Tasks;

namespace project.Views.Popups
{
    public partial class ExercisePopup : Rg.Plugins.Popup.Pages.PopupPage
    {
        public ExercisePopup()
        {
            InitializeComponent();
            BindingContext = new ViewModel.ExercisePopupViewModel();
        }

        protected override void OnAppearing()
        {
            base.OnAppearing();
        }

        protected override void OnDisappearing()
        {
            base.OnDisappearing();
        }

        protected override void OnAppearingAnimationBegin()
        {
            base.OnAppearingAnimationBegin();
        }

        protected override void OnAppearingAnimationEnd()
        {
            base.OnAppearingAnimationEnd();
        }
        protected override void OnDisappearingAnimationBegin()
        {
            base.OnDisappearingAnimationBegin();
        }
        protected override void OnDisappearingAnimationEnd()
        {
            base.OnDisappearingAnimationEnd();
        }

        protected override Task OnAppearingAnimationBeginAsync()
        {
            return base.OnAppearingAnimationBeginAsync();
        }

        protected override Task OnAppearingAnimationEndAsync()
        {
            return base.OnAppearingAnimationEndAsync();
        }

        protected override Task OnDisappearingAnimationBeginAsync()
        {
            return base.OnDisappearingAnimationBeginAsync();
        }

        protected override Task OnDisappearingAnimationEndAsync()
        {
            return base.OnDisappearingAnimationEndAsync();
        }
        protected override bool OnBackButtonPressed()
        {
            return base.OnBackButtonPressed();
        }
        protected override bool OnBackgroundClicked()
        {
            return base.OnBackgroundClicked();
        }
    }
}