Rails.application.routes.draw do
  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html


  root 'welcome#index'
  get '/work', to:'welcome#work'
  get '/test', to:'welcome#test'
  get '/root', to:'welcome#index'
end
